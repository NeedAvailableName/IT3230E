#include<stdio.h>
#include<string.h>
#define SIZE 81
int main() {
    char s[SIZE];
    FILE *fptr1=fopen("file1.txt","r");
    if(fptr1==NULL) printf("cannot open file1\n");
    FILE *fptr2=fopen("file2.txt","w");
    if(fptr2==NULL) printf("cannot open file2\n");
    while(fgets(s,SIZE,fptr1)!=NULL) {
        fprintf(fptr2,"%d %s",strlen(s)-1,s);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}