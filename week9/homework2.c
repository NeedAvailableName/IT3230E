/*Use the stack to write an arithmetic calculator program that has a menu interface:
1. Enter arithmetic expressions in infix notation (operands are one-digit integers)
2. Change to postfix form
3. Calculating value (if expression is wrong - inform users)
4. Exit*/
typedef char elementType;
#include"stackRec.h"
#include<ctype.h>
#include<string.h>

int prior(char c) {
    if(c == 'x' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

void func1(char str[]) {
    printf("Enter an arithmetic expression in infix notation: ");
    fflush(stdin);
    gets(str);
}

void func2(char str[], char result[]) {
    StackType s;
    initialize(&s);
    int i, j = 0;
    for(i = 0; i < strlen(str); i++) {
        if(isdigit(str[i] - '0') != 0) result[j++] = str[i];
        else if(str[i] == '(') push(str[i], &s);
        else if(str[i] == '+' || str[i] == '-' || str[i] == 'x' || str[i] == '/') {
            if(prior(peak(s)) < prior(str[i]) || isEmpty(s) == 0) push(str[i], &s);
            else {
                result[j++] = pop(&s);
                push(str[i], &s);
            }
        }
        else if(str[i] == ')') {
            while(pop(&s) != '(') {
                result[j++] = pop(&s);
            }
        }
    }
    while(!isEmpty(s)) result[j++] = pop(&s);
    printf("The postfix is: ");
    j = 0;
    while(result[j] != '0') {
        printf("%c ", result[j]);
        j++;
    }
}

void func3(char result[]) {
    StackType s;
    initialize(&s);
    int i;
    for(i = 0; i < strlen(result); i++) {
        if(isdigit(result[i] - '0') != 0) push(result[i], &s);
        else if(result[i] == '+') {
            push((pop(&s) - '0') + (result[i] - '0'), &s);
        }
        else if(result[i] == '-') {
            push((pop(&s) - '0') - (result[i] - '0'), &s);
        }
        else if(result[i] == 'x') {
            push((pop(&s) - '0') * (result[i] - '0'), &s);
        }
        else if(result[i] == '/') {
            push((pop(&s) - '0') / (result[i] - '0'), &s);
        }
    }
    printf("The result is: %d\n", pop(&s));
}

int main() {
    int opt;
    char str[MAX], result[MAX];
    do {
        printf("\n");
        printf("1. Enter arithmetic expressions in infix notation\n");
        printf("2. Change to postfix form\n");
        printf("3. Calculate value\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                func1(str);
            }
            break;
            case 2: {
                func2(str, result);
            }
            break;
            case 3: {
                func3(result);
            }
            break;
            case 4: {
                printf("Exit\n");
            }
            break;
            default:
            break;
        }
    } while(opt != 4);
}