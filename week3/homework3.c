/*Creat a text file whose content is a class list of at least 6 students.
Each line includes the following 4 fields:
No Student_number First_name (do not contain space characters) Phone_number
1 20181110 Bui_Van 0903112234
2 20182111 Joshua_Kim 0912123232
Then read this information from the file into an array of elements of structural type.
Program ask user to input mark (score) for each student and
record the results in the file bangdiem.txt which has the corresponding score field for each student.*/
#include<stdio.h>
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
    int i=0,j;
    FILE *fptr1=fopen("student_list.txt","r");
    FILE *fptr2=fopen("bangdiem.txt","w");
    if(fptr1==NULL) printf("cannot open file\n");
    while(fscanf(fptr1, "%d %s %s %s\n", &a[i].no, a[i].student_num, a[i].name, a[i].phone_num)!=EOF) {
        printf("%d\t%s\t%s\t%s\n", a[i].no, a[i].student_num, a[i].name, a[i].phone_num);
        i++;
    }
    if(fptr2==NULL) printf("cannot open file\n");
    for(j=0;j<i;j++) {
        printf("enter the score of %s: ", a[j].student_num);
        scanf("%f", &a[j].score);
        fprintf(fptr2,"%d\t%s\t%-15s\t%s\t%.2f\n",a[j].no,a[j].student_num,a[j].name,a[j].phone_num,a[j].score);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}