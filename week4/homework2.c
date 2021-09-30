/*Make change to the last week exercise program about Class List and transcript as follows:
Instead of static arrays, use pointers and dynamically allocate the amount of memory needed for the data stored in the class list file.
Add <input more> feature: the program asks for the number of additional students and 
reallocate the memory using realloc function and get input of new students.
Attention: class list file must contain ten students.*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
typedef struct {
    int no;
    char student_num[SIZE];
    char name[SIZE];
    char phone_num[SIZE];
    float score;
} student;
int main() {
    student a[SIZE];
    student *ptr;
    int i=0,j,n,num;
    FILE *fptr1=fopen("class_list.txt","r");
    FILE *fptr2=fopen("transcript.txt","w");
    if(fptr1==NULL) printf("cannot open file\n");
    while(fscanf(fptr1, "%d %s %s %s\n", &a[i].no, a[i].student_num, a[i].name, a[i].phone_num)!=EOF) {
        printf("%d\t%s\t%-20s\t%s\n", a[i].no, a[i].student_num, a[i].name, a[i].phone_num);
        i++;
    }
    if(fptr2==NULL) printf("cannot open file\n");
    for(j=0;j<i;j++) {
        printf("enter the score of %s: ", a[j].student_num);
        scanf("%f", &a[j].score);
        fprintf(fptr2,"%d\t%s\t%-20s\t%s\t%.2f\n",a[j].no,a[j].student_num,a[j].name,a[j].phone_num,a[j].score);
    }
    printf("Enter the number of additional students\n");
    scanf("%d", &num);
    ptr=realloc(ptr,num*sizeof(student));
    for(i=0;i<num;i++) {
        printf("enter the no: ");
        scanf("%d", &a[i].no);
        printf("enter the student number:");
        scanf("%s", a[i].student_num);
        printf("enter the name: ");
        scanf("%s", a[i].name);
        printf("enter the phone number: ");
        scanf("%s", a[i].phone_num);
        printf("enter the score: ");
        scanf("%f", &a[i].score);
        fprintf(fptr2,"%d\t%s\t%-20s\t%s\t%.2f\n", a[i].no, a[i].student_num, a[i].name, a[i].phone_num, a[i].score);
    }
    fclose(fptr1);
    fclose(fptr2);
    free(ptr);
    return 0;
}