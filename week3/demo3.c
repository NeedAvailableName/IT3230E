#include<stdio.h>
#include<stdlib.h>
#define SIZE 81
int main(int argc, char *argv[]) {
    if(argc!=4) {
        printf("wrong syntax\n");
        printf("enter merge file1 file2 file3\n");
    }
    else {
        char s[SIZE];
        int a=0,b=0;
        argv[1]="file1.txt";
        argv[2]="file2.txt";
        argv[3]="file3.txt";
        FILE *fptr1=fopen(argv[1],"r");
        if(fptr1==NULL) printf("cannot open file1\n");
        FILE *fptr2=fopen(argv[2],"r");
        if(fptr2==NULL) printf("cannot open file2\n");
        FILE *fptr3=fopen(argv[3],"w");
        if(fptr3==NULL) printf("cannot open file3\n");
        while(1) {
            if(fgets(s,SIZE,fptr1)!=NULL) {
                fputs(s,fptr3);
            }
            else a=1;
            if(fgets(s,SIZE,fptr2)!=NULL) {
                fputs(s,fptr3);
            }
            else b=1;
            if(a==1&&b==1) break;
        }    
        fclose(fptr1);
        fclose(fptr2);
        fclose(fptr3);
    }
    return 0;
}