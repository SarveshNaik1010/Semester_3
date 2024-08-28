#include<stdio.h>

int max = 3;
int stack[3];
int top = -1;

void main() {
    printf("Welcum to Stack operations\n");
    push();
}

void push() {
    int num;
    printf("\n%d\n", top);
    if(top == (max - 1)) {
        printf("Stack Overflow | Tumhari maa ki chut!");
    } else {
        top++;
        printf("Enter the element: ");
        scanf("%d", &num);
        stack[top] = num;
        display();
    }
}

void display() {
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
        printf("\n");
    push();
}