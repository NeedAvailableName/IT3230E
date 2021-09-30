#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
//typedef int Eltype;
typedef struct stackRec2 {
    elementType2 storage[MAX];
    int top2;
};
typedef struct stackRec2 StackType2;
void Initialize(StackType2 *stack) {
    (*stack).top2 = 0;
}
int IsEmpty(StackType2 stack) {
    return stack.top2 == 0;
}
int IsFull(StackType2 stack) {
    return stack.top2 == MAX;
}
void Push(elementType2 el, StackType2 *stack) {
    if(IsFull(*stack)) {
        printf("stack overflow\n");
    }
    else (*stack).storage[(*stack).top2++] = el;
}
elementType2 Pop(StackType2 *stack) {
    if(IsEmpty(*stack)) {
        printf("stack underflow\n");
    }
    else return (*stack).storage[--(*stack).top2];
}
elementType2 Peak(StackType2 *stack) {
    if(IsEmpty(*stack)) {
        printf("stack is empty\n");
        return -999999;
    }
    else return stack->storage[stack->top2 - 1];
}