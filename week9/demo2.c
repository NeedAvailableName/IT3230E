typedef int elementType;
#include"stackRec.h"
int main() {
    char num1[MAX], num2[MAX];
    StackType s1, s2, result;
    int i, carry = 0;
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
    while(!isEmpty(s1) || !isEmpty(s2)) {
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
    if(carry != 0) push(carry, &result);
    printf("The sum is: ");
    while(!isEmpty(result)) {
        printf("%d", pop(&result));
    }
    return 0;
}