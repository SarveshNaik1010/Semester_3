#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself if it's the first node
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;  // Move head to the new first node
    }
    printf("Inserted data %d at begining\n", data);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    
    if (*head == NULL) {
        newNode->next = newNode; // First node points to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Last node points back to head
    }
    printf("Data %d inserted\n", data);
}

// Function to delete a node with specific data
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head, *prev;

    // If the node to be deleted is the head node
    if (temp->data == key) {
        if (temp->next == *head) {  // Single node case
            *head = NULL;
            free(temp);
            return;
        }
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    prev = temp;
    temp = temp->next;
    while (temp != *head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If node not found
    if (temp == *head) {
        printf("Node with data %d not found\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// Main function to test the circular linked list
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);

    printf("Circular Linked List: ");
    displayList(head);

    // Delete a node
    deleteNode(&head, 20);
    printf("After deleting 20: ");
    displayList(head);

    return 0;
}
