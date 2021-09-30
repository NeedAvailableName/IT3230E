#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
typedef struct stack {
    int top;
    long capacity;
    int *array;
}stack;
long capacity = 100;
stack *s1, *s2, *s3;

char num1[] = "123456789";
char num2[] = "123456789";

int stackFull(stack *s) {
    return s->top == s->capacity - 1; 
}
 
int stackEmpty(stack *s) {   
    return s->top == -1;  
}

void push(stack *s, int item) {
    if (stackFull(s)) return;
    s->array[++s->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(stack *s) {
    if (stackEmpty(s)) return INT_MIN;
    return s->array[s->top--];
}

void pushStack(char num1[], char num2[]) {
    int i;
    for (i = 0; i < strlen(num1); i++) {
        push(s1, num1[i] - '0');
    }
    for(i = 0; i < strlen(num2); i++) {
        push(s2, num2[i] - '0');
    }
}

void displayStack(stack *s) {
    int i;
    for(i = 0; i <= s->top; i++) {
        printf("%d", s->array[i]);
    }
}

int main() {
    s1 = (stack *)malloc(sizeof(stack));
    s2 = (stack *)malloc(sizeof(stack));
    s3 = (stack *)malloc(sizeof(stack));
    int carry = 0;
    pushStack(num1, num2);
    while(stackEmpty(s1) != -1 || stackEmpty(s2) != -1) {
        int result = pop(s1) + pop(s2) + carry;
        if(result > 10) {
            push(s3, result - 10);
            carry = 1;
        }
        else {
            push(s3, result);
            carry = 0;
        }
    }
    if(carry != 0) push(s3, carry);
    displayStack(s3);
    free(s1);
    free(s2);
    free(s3);
}
