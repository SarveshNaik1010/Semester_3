from flask import Flask, render_template, request, jsonify;
import pymongo
from pymongo import ReturnDocument
import json

# DB Setup
client = pymongo.MongoClient('localhost:27017');
db = client['library']
collection = db['users']

# Creating the server
app = Flask(__name__)

def sendResponse(status, message="", documents=None):
    if(documents == None): return {"status": status, "message": message }
    return {"status": status, "message": message, "data": documents };




# Frontend
@app.route("/")
def home():
    return render_template('home.html')

@app.route("/login")
def login():
    return render_template('login.html')

@app.route("/library")
def library():
    return render_template('library.html')


# Backend
@app.route('/api/v1/user', methods=['GET', 'POST'])
def manageUsers():
    if(request.method == 'POST'):
        body = request.get_json();
        cursor = collection.find();
        for document in cursor:
            if(document['username'] == body['username']):
                return jsonify({"status": "error", "message": f"username '{body['username']}' is already taken!"})
        collection.insert_one(body);
        return (jsonify({"status": "success", "message": "User created successfully"}))
    if(request.method == 'GET'):
        cursor = collection.find();
        users = [];
        for document in cursor:
            document['_id'] = str(document['_id']);
            users.append(document)
        print(users)
        return users;

@app.route('/api/v1/user/<string:name>', methods=['PATCH'])
def updateUser(name):
    body = request.get_json()
    updatedUser = collection.find_one_and_update({'username': name}, {"$set": body}, return_document=ReturnDocument.AFTER)
    if(updatedUser == None): return sendResponse("error", "User does not exists")
    updatedUser['_id'] = str(updatedUser['_id']);
    return sendResponse('success', "User updated succesfully", updatedUser);

    

if __name__ == '__main__':
    app.run(debug=True)  # Enable debug mode