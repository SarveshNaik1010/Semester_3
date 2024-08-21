// infix_to_prefix.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
char result[MAX];
int top = -1;
int resIndex = 0;

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
    while (top != -1 && priorityChecker(stack[top]) > priorityChecker(operator)) {
        result[resIndex++] = pop();
    }
    push(operator);
}

void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - 1 - i];
        exp[len - 1 - i] = temp;
    }
}

void infixToPrefix(char* expression) {
    reverse(expression);
    for (int i = 0; i < strlen(expression); i++) {
        char ele = expression[i];

        if (isalpha(ele)) {
            result[resIndex++] = ele;
        } else if (strchr("+-*/^", ele)) {
            handleOperators(ele);
        } else if (ele == ')') {
            push(ele);
        } else if (ele == '(') {
            while (stack[top] != ')') {
                result[resIndex++] = pop();
            }
            pop();
        }
    }

    while (top != -1) {
        result[resIndex++] = pop();
    }

    result[resIndex] = '\0';
    reverse(result);
}

int main() {
    char expression[MAX];
    
    printf("Enter infix expression: ");
    fgets(expression, MAX, stdin);
    
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    infixToPrefix(expression);

    printf("Prefix expression: %s\n", result);
    
    return 0;
}
