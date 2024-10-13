import streamlit as st
from model import url;
from model import key;
import requests;


currUser = open('user.json', 'r');

def handleSearch():
    print(st.session_state['input-search'])
    print(st.session_state['input-cate'])
    if(st.session_state['input-cate'] == 'Book Name'):
        st.write(st.session_state['input-cate'])
        res = requests.get(url=f"{url}title={st.session_state['input-search']}&api-key=7xlAIKMETqY2V23B1B7rtASc4jfaNokW")
        data = res.json()
        for book in data["results"]:
            st.markdown(f"### Title: {book['title']}")
            st.write(f"**Description:** {book['description']}")
            st.write(f"**Author:** {book['author']}")
            st.write(f"**Contributor:** {book['contributor']}")
            st.write(f"**Publisher:** {book['publisher']}")

    
    if(st.session_state['input-cate'] == 'Author'):
        st.write(st.session_state['input-cate'])
        res = requests.get(url=f"{url}author={st.session_state['input-search']}&api-key=7xlAIKMETqY2V23B1B7rtASc4jfaNokW")
        data = res.json()
        for book in data["results"]:
            st.markdown(f"### Title: {book['title']}")
            st.write(f"**Description:** {book['description']}")
            st.write(f"**Author:** {book['author']}")
            st.write(f"**Contributor:** {book['contributor']}")
            st.write(f"**Publisher:** {book['publisher']}")


def displayLibrary():
    st.title("Library");
    col1, col2, col3 = st.columns([3, 2, 1])  # Adjust the ratio for the columns as needed

    with col1:
        st.text_input("Enter book name:", key='input-search')

    with col2:
        st.selectbox("Category:", ["Book Name", "Author"], key='input-cate')

    with col3:
        st.button("Search", on_click=handleSearch)

displayLibrary();