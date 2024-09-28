#include <stdio.h>

int top = -1;

int stack[10];

int push(int ele) {
    if(top == 10) {
        printf("Stack overflow\n");
        return 0;
    }
    top++;
    stack[top] = ele;
    printf("Element %d inserted successfully\n", stack[top]);
    return 1;
}

int pop() {
    if(top == -1) {
        printf("Stack underflow\n");
        return 0;
    }
    printf("Element popped successfully");
    top--;
}

int display() {
    if(top == -1) {
        printf("Please insert element before\n");
        return 0;
    }
    printf("[");
    for(int i = top; i >= 0; i--) {
        printf("%d, ", stack[i]);
    }
    printf("]\n");
    return 1;
}

void main() {
    int flag = 1, op, ele;

    printf("Welcome to stack operation\n");
    while(flag == 1) {
        printf("Select stack operation\n1. Push\n2. Pop\n3. Display\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1: {
                printf("Enter the element that you want to push: ");
                scanf("%d", &ele);
                push(ele);
                break;
            } 

            case 2: {
                pop();
                break;
            } 

            case 3: {
                display();
                break;
            } 
                
            
            default: {
                printf("Please enter one of these numbers => 1, 2 or 3\n");
                break;
            }
        }
    }
}

