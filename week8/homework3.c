//write a program that find out the first capital character in a string using recursion
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 100
int i = 0;
char find_capital(char *str) {
    if(i < strlen(str)) {
        if(isupper(str[i]) == 1) return str[i];
        else {
            i++;
            find_capital(str);
        }
    }
}
int main() {
    char str[SIZE];
    printf("Enter the string\n");
    gets(str);
    printf("%c", find_capital(str));
    return 0;
}