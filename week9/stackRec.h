#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
typedef int Eltype;
typedef struct stackRec {
    Eltype storage[MAX];
    int top;
};
typedef struct stackRec StackType;
void initialize(StackType *stack) {
    (*stack).top = 0;
}
int isEmpty(StackType stack) {
    return stack.top == 0;
}
int isFull(StackType stack) {
    return stack.top == MAX;
}
void push(Eltype el, StackType *stack) {
    if(isFull(*stack)) {
        printf("stack overflow\n");
    }
    else (*stack).storage[(*stack).top++] = el;
}
Eltype pop(StackType *stack) {
    if(isEmpty(*stack)) {
        printf("stack underflow\n");
    }
    else return (*stack).storage[--(*stack).top];
}
Eltype peak(StackType stack) {
    if(isEmpty(stack)) {
        printf("stack is empty\n");
        return -999999;
    }
    else return stack.storage[stack.top - 1];
}