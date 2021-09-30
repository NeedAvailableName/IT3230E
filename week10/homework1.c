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
typedef int elementType1;
typedef char* elementType2;
#include"stackRec1.h"
#include"stackRec2.h"

char *intToChar(int n){
    char *result = (char *)malloc(20);
    itoa(n, result, 10);
    return result;
}

void func1(StackType1 s1, StackType2 s2) {
    int num;
    char *str = (char *)malloc(MAX);
    printf("Enter the number to add: ");
    scanf("%d", &num);
    push(num, &s1);
    strcpy(str, "PUSH ");
    strcat(str, intToChar(num));
    Push(str, &s2);
}

void func2(StackType1 s1) {
    printf("The top is %d", peak(&s1));
}

void func3(StackType1 s1, StackType2 s2) {
    char *str = (char *)sizeof(MAX);
    strcpy(str, "POP ");
    strcat(str, intToChar(peak(&s1)));
    pop(&s1);
    Push(str, &s2);
    printf("Successful\n");
}

void func4(StackType1 s1, StackType2 s2) {
    char *str = (char *)malloc(MAX);
    int n;
    sscanf(Peak(&s2), "%s %d", str, &n);
    if(strcmp(str, "POP") == 0) {
        Pop(&s2);
        push(n, &s1);
    }
    else if(strcmp(str, "PUSH") == 0) {
        Pop(&s2);
        pop(&s1);
    }
}
int main() {
    StackType1 s1;
    initialize(&s1);
    StackType2 s2;
    Initialize(&s2);
    int opt;
    do {
        printf("\n");
        printf("1. Add one integer to the stack\n");
        printf("2. View top\n");
        printf("3. Remove from the stack contains integers one element\n");
        printf("4. Undo\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                func1(s1, s2);
            }
            break;
            case 2: {
                func2(s1);
            }
            break;
            case 3: {
                func3(s1, s2);
            }
            break;
            case 4: {
                func4(s1, s2);
            }
            break;
            case 5: {
                printf("Exit\n");
            }
            break;
            default:
            break;
        }
    }while(opt != 5);
    return 0;
}
