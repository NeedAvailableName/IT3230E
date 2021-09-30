/*Implement and demo the function char *subStr(char *s1, int offset, int number)
This function take the subString of s1 that starts from the character with offset index(start from 0) 
and has number characters.
Remember to check the validation of the parameters.
In the case that the number is greater than the number of characters resting from offset to the end of s1.
Return the subString of s1 from offset.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
char *subStr(char *s1, int offset, int number) {
    char *sub=malloc(strlen(s1)*sizeof(char));
    if(sub==NULL) printf("memory allocation failed\n");
    int i;
    for(i=0;i<number;i++) {
        *(sub+i)=*(s1+offset-1);
        s1++;
    }
    return sub;
}
int main() {
    char *ptr=malloc(SIZE*sizeof(char));
    if(ptr==NULL) printf("memory allocation failed\n");
    int offset,number;
    printf("Enter the string\n");
    gets(ptr);
    printf("Enter offset index: ");
    scanf("%d", &offset);
    while(offset<0) {
        printf("please enter a positive number: ");
        scanf("%d", &offset);
    }
    printf("Enter number of characters: ");
    scanf("%d", &number);
    while(number<0) {
        printf("please enter a positive number: ");
        scanf("%d", &number);
    }
    printf("%s",subStr(ptr,offset,number));
    free(ptr);
    return 0;
}