#include<stdio.h>
#include<stdlib.h>
#define SIZE 81
int main(int argc, char *argv[]) {
    int count=0;
    if(argc!=2) {
        printf("wrong syntax\n");
        printf("enter demo file1\n");
    }
    else {
        argv[1]="file1.txt";
        FILE *fptr1=fopen(argv[1],"r");
        if(fptr1==NULL) printf("cannot open file1\n");
        char s[SIZE];
        while(fgets(s,SIZE,fptr1)!=NULL) {
            printf("%s",s);
            count++;
        }
        printf("\n%d\n", count);
        fclose(fptr1);
    }
    return 0;
}