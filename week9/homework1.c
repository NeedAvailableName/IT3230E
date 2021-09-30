/*Complete three libraries for stack using:
array (stackarr.h)
record (stackRec.h)
linked list (stacklist.h)
Write a program to using one among these lib to:
a) add very large integer numbers
b) subtract very large integer numbers*/
typedef int elementType;
#include"stackRec.h"

void func1(char num1[], char num2[]) {
    StackType s1, s2, result;
    int i, carry = 0;
    initialize(&s1);
    initialize(&s2);
    initialize(&result);
    printf("Enter the number 1:\n");
    gets(num1);
    fflush(stdin);
    printf("Enter the number 2:\n");
    gets(num2);
    for(i = 0; i < strlen(num1); i++) {
        push(num1[i] - '0', &s1);
    }
    for(i = 0; i < strlen(num2); i++) {
        push(num2[i] - '0', &s2);
    }
    if(strlen(num1) <= strlen(num2)) {
        while(!isEmpty(s1)) {
            int sum = pop(&s1) + pop(&s2) + carry;
            if(sum > 10) {
                push(sum - 10, &result);
                carry = 1;
            }
            else {
                push(sum, &result);
                carry = 0;
            }
        }
        if(carry == 1) {
            push(pop(&s2) + carry, &result);
        }
        while(!isEmpty(s2)) push(pop(&s2), &result);
        printf("The sum is: ");
        while(!isEmpty(result)) {
            printf("%d", pop(&result));
        }
        printf("\n");
    }
    else {
        while(!isEmpty(s2)) {
            int sum = pop(&s1) + pop(&s2) + carry;
            if(sum >= 10) {
                push(sum - 10, &result);
                carry = 1;
            }
            else {
                push(sum, &result);
                carry = 0;
            }
        }
        if(carry == 1) {
            push(pop(&s1) + carry, &result);
        }
        while(!isEmpty(s1)) push(pop(&s1), &result);
        printf("The sum is: ");
        while(!isEmpty(result)) {
            printf("%d", pop(&result));
        }
        printf("\n");
    }
}
    
   

void func2(char num1[], char num2[]) {
    StackType s1, s2, result;
    int i, carry = 0, subtract;
    initialize(&s1);
    initialize(&s2);
    initialize(&result);
    printf("Enter the number 1:\n");
    gets(num1);
    printf("Enter the number 2:\n");
    gets(num2);
    for(i = 0; i < strlen(num1); i++) {
        push(num1[i] - '0', &s1);
    }
    for(i = 0; i < strlen(num2); i++) {
        push(num2[i] - '0', &s2);
    }
    while(!isEmpty(s2)) {
        subtract = pop(&s1) - pop(&s2) - carry;
        if(subtract < 0) {
            subtract = 10 + subtract;
            carry = 1;
            push(subtract, &result);
        }
        else {
            push(subtract, &result);
            carry = 0;
        }
    }
    while(!isEmpty(s1)) {
        if(carry == 1) {
            subtract = pop(&s1) - carry;
            if(subtract == -1) {
                subtract = 0;
                carry = 1;
                push(subtract, &result); 
            }
            else push(subtract, &result);
        }
        else push(pop(&s1), &result);
    }
    printf("The subtract is: ");
    while(!isEmpty(result)) {
        printf("%d", pop(&result));
    }
    printf("\n"); 
}

int main() {
    char num1[MAX], num2[MAX];
    StackType s1, s2, result;
    int opt;
    //initialize(&s1);
    //initialize(&s2);
    //initialize(&result);
    do {
        printf("1. Sum two integer numbers\n");
        printf("2. Subtract two integer number\n");
        printf("3. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        fflush(stdin);
        switch(opt) {
            case 1: {
                func1(num1, num2);
            }
            break;
            case 2: {
                func2(num1, num2);
            }
            break;
            case 3: printf("Exit\n");
            break;
            default:
            break;
        }
    } while(opt != 3);
    return 0;
}