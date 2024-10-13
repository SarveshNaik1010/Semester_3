import streamlit as st
import model as db
import json

st.session_state['currUser'] = '';

def handleLogin():
    username = st.session_state['username']
    password = st.session_state['password']
    for user in db.userData:
        if(user['username'] == username and user['password'] == password):
            st.link_button('Start Reading', url="/library")
            currUser = open('user.json', 'w')
            currUser.write(json.dumps(user))

    if st.session_state['currUser'] == None: 
        st.text("Incorrect username or password")


st.title("Login")
with st.container():
    st.text_input("Enter your name:", key='username')
    st.text_input("Enter password:", type="password", key="password")
    st.button("Login", on_click=handleLogin)
