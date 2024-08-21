// postfix_to_infix.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

void push(char *item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        strcpy(stack[++top], item);
    }
}

char *pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return NULL;
    } else {
        return stack[top--];
    }
}

void postfixToInfix(char* expression) {
    for (int i = 0; i < strlen(expression); i++) {
        char ele = expression[i];

        if (isalpha(ele)) {
            char operand[2] = {ele, '\0'};
            push(operand);
        } else if (strchr("+-*/^", ele)) {
            char *op2 = pop();
            char *op1 = pop();
            char temp[MAX] = "(";
            strcat(temp, op1);
            strncat(temp, &ele, 1);
            strcat(temp, op2);
            strcat(temp, ")");
            push(temp);
        }
    }
}

int main() {
    char expression[MAX];
    
    printf("Enter postfix expression: ");
    fgets(expression, MAX, stdin);
    
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    postfixToInfix(expression);

    printf("Infix expression: %s\n", pop());
    
    return 0;
}
