#include<stdio.h>

int stack[10];
int size = 5 - 1;
int top = -1;

int push() {
    if(top >= size) {
        printf("Stack Overflow!\n");
        return 0;
    }
    top++;
    printf("Enter a number to push: ");
    scanf("%d", &stack[top]);
    printf("Element %d pushed successfuly\n", stack[top]);
}

int pop() {
    if(top <= -1) {
        printf("Stack Underflow!\n");
        return 0;
    }
    printf("Element %d poped successfuly\n", stack[top]);
    top--;
}

int display() {
    printf("Elements are:\n");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void main() {
    printf("Welcome to Stack Operations 👋\n");
    while(1) {
        int choice;
        printf("Enter 1. Push, 2. Pop, 3. Display\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            default: printf("Please enter a valid number\n");
        }
    }
}