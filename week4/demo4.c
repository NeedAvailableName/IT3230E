#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int main() {
    int num;
    FILE *fptr1=fopen("lab1.txt","r");
    FILE *fptr2=fopen("lab1a.txt","w");
    char s[SIZE];
    while(!foef(fptr1)) {
        num=fread(s,sizeof(char),SIZE,fptr1);
        s[num*sizeof(char)]='0';
        fwrite(s,sizeof(char),SIZE,fptr2);
    }
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}