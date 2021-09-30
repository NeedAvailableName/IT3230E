#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
//typedef int Eltype;
typedef struct stackRec1 {
    elementType1 storage[MAX];
    int top1;
};
typedef struct stackRec1 StackType1;
void initialize(StackType1 *stack) {
    (*stack).top1 = 0;
}
int isEmpty(StackType1 stack) {
    return stack.top1 == 0;
}
int isFull(StackType1 stack) {
    return stack.top1 == MAX;
}
void push(elementType1 el, StackType1 *stack) {
    if(isFull(*stack)) {
        printf("stack overflow\n");
    }
    else (*stack).storage[(*stack).top1++] = el;
}
elementType1 pop(StackType1 *stack) {
    if(isEmpty(*stack)) {
        printf("stack underflow\n");
    }
    else return (*stack).storage[--(*stack).top1];
}
elementType1 peak(StackType1 *stack) {
    if(isEmpty(*stack)) {
        printf("stack is empty\n");
        return -999999;
    }
    else return stack->storage[stack->top1 - 1];
}