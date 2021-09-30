#include<stdio.h>
#include<stdlib.h>
#define SIZE 81
int main(int argc, char *argv[]) {
    if(argc!=3) {
        printf("wrong syntax\n");
        printf("enter demo file1 file2\n");
    }
    else {
        argv[1]="file1.txt";
        argv[2]="file2.txt";
        FILE *fptr1=fopen(argv[1],"r");
        if(fptr1==NULL) printf("cannot open file1\n");
        FILE *fptr2=fopen(argv[2],"w");
        if(fptr2==NULL) printf("cannot open file2\n");
        char s[SIZE];
        while(fgets(s,SIZE,fptr1)!=NULL) {
            fputs(s,fptr2);
        }
        fclose(fptr1);
        fclose(fptr2);
    }
    return 0;
}