#include <stdio.h>
#define MAX 100

typedef struct {
    int value;
    int priority;
} PriorityQueue;

PriorityQueue pq[MAX];
int size = 0;

// Function to insert an element into the priority queue 
void enqueue(int value, int priority) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    pq[size].value = value;
    pq[size].priority = priority;
    size++;
}

// Function to remove the highest priority element 
int dequeue() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int highestPriority = pq[0].priority;
    int pos = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i].priority > highestPriority) {
            highestPriority = pq[i].priority;
            pos = i;
        }
    }

    int dequeuedValue = pq[pos].value;

    for (int i = pos; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
    return dequeuedValue;
}

// Function to display the priority queue 
void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].value, pq[i].priority);
    }
}

int main() {
    enqueue(10, 3);
    enqueue(20, 2);
    enqueue(30, 5);
    enqueue(40, 1);

    display();

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    display();

    return 0;
}
