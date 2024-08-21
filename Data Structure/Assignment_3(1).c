#include <stdio.h>
#include <ctype.h>  // for isalpha() function
#include <string.h> // for strlen() function

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

int priorityChecker(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    if (operator == '^') return 3;
    return 0;
}

void handleOperators(char operator) {
    while (top != -1 && priorityChecker(stack[top]) >= priorityChecker(operator)) {
        printf("%c", pop());
    }
    push(operator);
}

void infixToPostFix(char* expression) {
    for (int i = 0; i < strlen(expression); i++) {
        char ele = expression[i];

        if (isalpha(ele)) {
            printf("%c", ele);
        } else if (strchr("+-*/^", ele)) {
            handleOperators(ele);
        } else if (ele == '(') {
            push(ele);
        } else if (ele == ')') {
            while (stack[top] != '(') {
                printf("%c", pop());
            }
            pop();  // Remove '(' from the stack
        }
    }

    // Pop all the operators left in the stack
    while (top != -1) {
        printf("%c", pop());
    }
}

int main() {
    char expression[MAX];
    
    printf("Enter infix expression: ");
    fgets(expression, MAX, stdin);
    
    // Remove newline character from the end if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    printf("Postfix expression: ");
    infixToPostFix(expression);
    printf("\n");
    
    return 0;
}
