#include"stackRec.h"
int top = 0;
void check(char str[]) {
    StackType s;
    initialize(&s);
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            top = top + 1;
            push(str[i], &s);
        }
        if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if(peak(s) == '(' && str[i] == ')') {
                pop(&s);
                top = 0;
            }
            else if(peak(s) == '[' && str[i] == ']') {
                pop(&s);
                top = 0;
            }
            else if(peak(s) == '{' && str[i] == '}') {
                pop(&s);
                top = 0;
            }
            else top++;
        }
    }
    if(top == 0)
        printf("String is balanced!\n");
    else
        printf("String is unbalanced!\n");
}
 
int main() {
    char str[MAX];
    printf("Enter the string:\n");
    gets(str);
    check(str);
    return 0;
}