#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

// Peek function
int peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;
    int result[n];

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && peek() <= arr[i]) {
            pop();
        }

        if (isEmpty()) {
            result[i] = -1;
        } else {
            result[i] = peek();
        }

        push(arr[i]);
    }

    // Print result
    printf("Next Greater Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }

    return 0;
}