/*write a program that ask user to input a number of students in a class, then their full name in Vietnamese.
Print the student list sorted by the first name of student.
Print the maximum number of students who have the same first name*/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100
typedef struct{
    char student[40];
    char fname[10];
}class_t;
class_t class[SIZE];
char *first(char *a){
    int i;
    for (i=strlen(a)-1;i>=0;i--){
        if(a[i]==' ') break;
    }
    return (a+i+1);
}
void swap(class_t *a, class_t *b){
    class_t c;
    c = *a;
    *a = *b;
    *b = c;
}
int main(){
    int i, j, n, max = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Student %d: ", i + 1);
        fflush(stdin);
        gets(class[i].student);
        sscanf(first(class[i].student), "%s",class[i].fname);
    }
    for(i = 0; i < n - 1 ; i++)
        for(j = 0; j < n - 1; j++){
            if (strcmp(class[j].fname, class[j+1].fname) > 0)
               swap(&class[j], &class[j+1]);
        }
    for(i = 0; i < n; i++){
        printf("%s\n", class[i].student);
    }
    for(i = 0; i < n - 1 ; i++){
        int check = 0;
        for(j = 0; j < n - 1; j++){
            if(strcmp(class[i].fname, class[j].fname) == 0)
                check ++;
        }
        if(check > max) max = check;
    }
    printf("Max = %d\n", max);
}
