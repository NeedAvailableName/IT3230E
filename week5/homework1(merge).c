/*write a merge file program that work with the following syntax:
filemerge phone1.dat phone2.dat phone.dat*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 80
typedef struct {
    char name[SIZE];
    char phone[SIZE];
    char email[SIZE];
} contact;
int main() {
    FILE *fptr = fopen("phone.dat", "r+b");
    if(fptr==NULL) printf("cannot open file\n");
    FILE *fptr1 = fopen("phone1.dat", "r+b");
    if(fptr1==NULL) printf("cannot open file\n");
    FILE *fptr2 = fopen("phone2.dat", "r+b");
    if(fptr2==NULL) printf("cannot open file\n");
    contact s[SIZE];
    while(!feof(fptr1)) {
        if(fread(s,SIZE*sizeof(char),1,fptr1)!=0)
        fwrite(s,SIZE*sizeof(char),1,fptr);
    }
    while(!feof(fptr2)) {
        if( fread(s, SIZE*sizeof(char), 1, fptr2)!=0)
        fwrite(s, SIZE*sizeof(char), 1, fptr);
    }
    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}