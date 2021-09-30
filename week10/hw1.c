/*Write a program that simulates the Undo function of editors(Ofice, Text editor,...) as follows. 
The program uses two stacks: A stack contains integers and a stack 
contains elements that are strings and have the following menu inteface:
- Add 1 integer to the stack
- View top
- Remove from the stack contains integers 1 element
- Undo
Hint: To set the undo function, we save the name of the operations just done 
on the integer stack in string stack (except the View top operation bacause it does not change the data). 
The program based on the last action that was taken to do the opposite.
For example:
- PUSH 20 -> UNDO = TOP
- POP 15 -> UNDO PUSH 15*/
typedef int Eltype;
typedef char* Eltype2;
#include"stackList.h"
#include"stackList2.h"

char *intToChar(int n) {
    char *result = (char *)malloc(20);
    itoa(n, result, 10);
    return result;
}

void addInt(int n, stackType *stackInt, stackType2 *stackChar) {
    push(n, stackInt);
    char *op = (char*)malloc(20);
    strcpy(op, "PUSH ");
    strcat(op, intToChar(n));
    push2(op, stackChar);
    printf("Successful\n");
}

void viewTop(stackType stackInt) {
    if(stackInt != NULL){
        printf("Top is: %d\n", peek(&stackInt));
        return;
    }
    printf("Stack empty\n");
}

/*void viewTop2(stackType2 stackChar){
    printf("Top 2: %s\n", peek2(&stackChar));
}*/

void removeInt(stackType *stackInt, stackType2 *stackChar) {
    if(*stackInt == NULL) {
        printf("Stack underflow!\n");
        return;
    }
    int n = pop(stackInt);
    char *op = (char*)malloc(20);
    strcpy(op, "POP ");
    strcat(op, intToChar(n));
    push2(op, stackChar);
    printf("Successful\n");
}

void undo(stackType *stackInt, stackType2 *stackChar) {
    char *op = (char*)malloc(10);
    int n;
    if(isEmpty2(*stackChar)) {
        printf("Cannot undo, no previous operation\n");
        return;
    }
    sscanf(pop2(stackChar), "%s %d", op, &n);
    if(strcmp(op, "PUSH") == 0) {
        pop(stackInt);
        printf("Successful\n");
        // removeInt(stackInt, stackChar);
        return;
    }
    if(strcmp(op, "POP") == 0) {
        push(n, stackInt);
        printf("Successful\n");
        // addInt(n, stackInt, stackChar);
    }
}

int main() {
    stackType stackInt = NULL;
    stackType2 stackChar = NULL;
    int n;
    int opt;
    do{
        printf("\n");
        printf("1. Add 1 integer to the stack\n");
        printf("2. View top\n");
        printf("3. Remove from the stack contains integers 1 element\n");
        printf("4. Undo\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                addInt(n, &stackInt, &stackChar);
                break;
            case 2:
                viewTop(stackInt);
                break;
            case 3:
                removeInt(&stackInt, &stackChar);
                break;
            case 4:
                undo(&stackInt, &stackChar);
                break;
            case 5:
                freeStack(&stackInt);
                freeStack2(&stackChar);
            default:
                break;
        }
    } while(opt != 5);
    // addInt(&stackInt, &stackChar);
    // viewTop(stackInt);
    // viewTop2(stackChar);
    // undo(&stackInt, &stackChar);
    // viewTop(stackInt);
}