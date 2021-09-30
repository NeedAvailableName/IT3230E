#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100 
int main() {
    char *s1=(char *)malloc(SIZE*sizeof(char));
    char *s2=(char *)malloc(SIZE*sizeof(char));
    char *mycat=(char *)malloc(sizeof(s1)+sizeof(s2));
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    strcpy(mycat,s1);
    strcat(mycat,s2);
    printf("%s", mycat);
    free(s1);
    free(s2);
    free(mycat);
    return 0;
}