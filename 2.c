#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0';  // Indicates empty stack
    } else {
        return stack[top--];
    }
}

// Function to check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

// Function to check balanced expression
int isBalanced(char expr[]) {
    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            char popped = pop();

            // If stack empty or not matching
            if (popped == '\0' || !isMatchingPair(popped, ch)) {
                return 0;
            }
        }
    }

    // If stack is empty → balanced
    return (top == -1);
}

int main() {
    char expr[MAX];

    printf("Enter expression: ");
    scanf("%s", expr);

    if (isBalanced(expr)) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced Expression\n");
    }

    return 0;
}