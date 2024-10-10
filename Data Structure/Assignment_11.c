#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Element %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the circular doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
    printf("Element %d inserted at the end.\n", data);
}

// Function to delete a node from the circular doubly linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;

    // If the node to be deleted is the only node in the list
    if (temp->data == key && temp->next == *head) {
        *head = NULL;
        free(temp);
        printf("Element %d deleted.\n", key);
        return;
    }

    // If the head node contains the key
    if (temp->data == key) {
        struct Node* last = temp->prev;
        *head = temp->next;
        last->next = *head;
        (*head)->prev = last;
        free(temp);
        printf("Element %d deleted.\n", key);
        return;
    }

    // Traverse the list to find the node to delete
    while (temp->next != *head && temp->data != key) {
        temp = temp->next;
    }

    // If the node to delete is found
    if (temp->data == key) {
        struct Node* prevNode = temp->prev;
        struct Node* nextNode = temp->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        free(temp);
        printf("Element %d deleted.\n", key);
    } else {
        printf("Key %d not found.\n", key);
    }
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function to demonstrate the circular doubly linked list
int main() {
    struct Node* head = NULL;

    // Insert nodes and display messages
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);

    // Display the list
    displayList(head);

    // Delete a node and display message
    deleteNode(&head, 20);
    displayList(head);

    return 0;
}
