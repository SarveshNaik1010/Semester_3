#include <stdio.h>
#include <stdlib.h>

struct List{
    int data;
    struct List* next;    
};

struct List* pushNode(struct List* Head, int data) {
    // struct List* newNode = (struct List*)malloc(sizeof(struct List));
    struct List* newNode = (struct List*)malloc(sizeof(struct List));
    newNode->data = data;
    newNode->next = Head == NULL ? NULL : Head;
    struct List* currNode = Head;

    if(Head == NULL) return newNode;

    currNode->next = newNode;

    printf("Element %d added to the list\n", newNode->data);

    return Head;
}

struct List* insertAtBegning(struct List* Head, int data) {
    struct List* currNode = (struct List*)malloc(sizeof(struct List));
    currNode->data = data;
    currNode->next = Head;
    Head = currNode;
    printf("%d\n", Head->data);
    return Head;
}

struct List* display(struct List* Head) {
    struct List* currNode = Head;
    while(currNode != NULL) {
        printf("Data - %d\n", currNode->data);
        currNode = currNode->next;
    }
    return Head;
}

struct List* pop(struct List* Head) {
    while(1) {
        struct List* nextNode = Head;
        while(1) {
            if(nextNode->next->next == NULL) {
                nextNode->next = NULL;
                break;
            }
            nextNode = nextNode->next;
        }
        printf("Element Popped\n");
        return Head;
    }
}

void main() {
    struct List* Head = pushNode(NULL, 10);
    pushNode(Head, 10);
    pushNode(Head, 20);
    pushNode(Head, 30);
    // Head = insertAtBegning(Head, 40);
    Head = pop(Head);
    display(Head);
}