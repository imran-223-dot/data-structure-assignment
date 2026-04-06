#include<stdio.h>
#include<string.h>
#define MAX 100
char stack[MAX];
int top = -1;
// Push function
int push(char ch) {
    if(top==MAX-1)
    {
        printf("stack overflow\n");
        return'\0';
    }
    else{
    stack[++top] = ch;
    }
}
// Pop function
char pop() {
    if(top==-1)
    {
        printf("stack overflow.\n");
    }
    else{
         stack[top--];
    } 
}

int main() {
    char str[100];
    int i;
    printf("Enter a string: ");
    scanf("%s", str);
    // Push all characters into stack
    for(i = 0; i < strlen(str); i++) {
        push(str[i]);
    }
    // Pop characters to reverse string
    printf("Reversed string: ");
    while(top != -1) {
        printf("%c", pop());
    }
    return 0;
}

