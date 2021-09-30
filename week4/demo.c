#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE *fptr1=fopen("file1.txt","r");
    FILE *fptr2=fopen("file2.txt","w");
    char *s=malloc(100*sizeof(char));
    while(!feof(fptr1)) {
        fread(s,sizeof(char),50,fptr1);
        fwrite(s,sizeof(char),50,fptr2);
        printf("%s", s);
    }
    return 0;
}