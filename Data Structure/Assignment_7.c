#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }
    deque[front] = value;
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = value;
}

int deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = deque[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
    return value;
}

int deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return -1;
    }
    int value = deque[rear];
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
    return value;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertFront(20);
    insertRear(30);
    insertFront(40);
    
    display();
    
    printf("Deleted from front: %d\n", deleteFront());
    printf("Deleted from rear: %d\n", deleteRear());
    
    display();
    
    return 0;
}
