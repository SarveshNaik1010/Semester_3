from flask import Flask, render_template, request, jsonify;
import pymongo
from pymongo import ReturnDocument
import json

# DB Setup
client = pymongo.MongoClient('localhost:27017');
db = client['library']
userCollection = db['users']
adminCollection = db['admin']

# Creating the server
app = Flask(__name__)

def sendResponse(status, message="", documents=None):
    if(documents == None): return {"status": status, "message": message }
    return {"status": status, "message": message, "data": documents };

# --------------------------------- Frontend --------------------------------- #
@app.route("/")
def homePage():
    return render_template('home.html')

@app.route("/login")
def loginPage():
    return render_template('login.html')

@app.route("/library")
def libraryPage():
    return render_template('library.html')


# ---------------------------------- backend --------------------------------- #

@app.route('/api/v1/user', methods=['GET', 'POST'])
def manageUsers():
    if(request.method == 'POST'):
        body = request.get_json();
        cursor = userCollection.find();
        for document in cursor:
            if(document['username'] == body['username']):
                return jsonify({"status": "error", "message": f"username '{body['username']}' is already taken!"})
        userCollection.insert_one(body);
        return (jsonify({"status": "success", "message": "User created successfully"}))
    if(request.method == 'GET'):
        cursor = userCollection.find();
        users = [];
        for document in cursor:
            document['_id'] = str(document['_id']);
            users.append(document)
        print(users)
        return users;

@app.route('/api/v1/user/<string:name>', methods=['GET', 'PATCH'])
def updateUser(name):
    body = request.get_json()
    updatedUser = userCollection.find_one_and_update({'username': name}, {"$set": body}, return_document=ReturnDocument.AFTER)
    if(updatedUser == None): return sendResponse("error", "User does not exists")
    updatedUser['_id'] = str(updatedUser['_id']);
    return sendResponse('success', "User updated succesfully", updatedUser);

@app.route('/user/authticate/login', methods=['POST'])
def userLogin():
    body = request.get_json()
    user = userCollection.find_one({"username": body['username']})
    print(user)
    if(user != None and int(user['password']) == int(body['password'])):
        user['_id'] = str(user['_id'])
        jsonStr = {
            "_id": user["_id"],
            "username": f"{user['username']}",
            "books": f"{user['books']}",
        }
        return {"status": "success", "isLoggedIn": True, "currUser": jsonStr}
    return {"status": "error", "message": "Incorrect username or password"}

@app.route('/user/authticate/logout', methods=['POST'])
def userLogout():
    return sendResponse({"status": "success", "isLoggedIn": False})

# ------------------------------- server setup ------------------------------- #
if __name__ == '__main__':
    app.run(debug=True)  # Enable debug mode