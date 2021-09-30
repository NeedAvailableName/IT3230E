/*Write a multi-modes copy program with menu driven interface providing these functionalities:
1. Copy by character
2. Copy by line
3. Copy by block-optional size
After finishing copying, print out the execution time on the screen for comparison.
Attention: source file should be a text file larger than 640kb.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 80
void copy_by_character(FILE *fptr1, FILE *fptr2) {
    char c;
    while((c=fgetc(fptr1))!=EOF) fputc(c,fptr2);
}
void copy_by_line(FILE *fptr1, FILE *fptr2) {
    char s[SIZE];
    while(fgets(s,SIZE,fptr1)!=NULL) fputs(s,fptr2);
}
void copy_by_block(FILE *fptr1, FILE *fptr2, int size) {
    char *a=malloc(size*sizeof(char));
    while(!feof(fptr1)) {
        fread(a,sizeof(char),size,fptr1);
        fwrite(a,sizeof(char),size,fptr2);
    }
}
int main() {
    clock_t start, end;
    int opt;
    do {
        printf("MENU\n");
        printf("1. Copy by character\n");
        printf("2. Copy by line\n");
        printf("3. Copy by block-optional size\n");
        printf("4.Exit\n");
        printf("Enter a option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                FILE *fptr1=fopen("file1.txt","r");
                if(fptr1==NULL) printf("cannot open file\n");
                FILE *fptr2=fopen("file2.txt","w");
                if(fptr2==NULL) printf("cannot open file\n");
                start=clock();
                copy_by_character(fptr1,fptr2);
                end=clock();
                printf("Time is %f\n", (double)(end-start)/CLOCKS_PER_SEC);
                fclose(fptr1);
                fclose(fptr2);
            };
            break;
            case 2: {
                FILE *fptr1=fopen("file1.txt","r");
                if(fptr1==NULL) printf("cannot open file\n");
                FILE *fptr2=fopen("file2.txt","w");
                if(fptr2==NULL) printf("cannot open file\n");
                start=clock();
                copy_by_line(fptr1,fptr2);
                end=clock();
                printf("Time is %f\n", (double)(end-start)/CLOCKS_PER_SEC);
                fclose(fptr1);
                fclose(fptr2);
            };
            break;
            case 3: {
                FILE *fptr1=fopen("file1.txt","r");
                if(fptr1==NULL) printf("cannot open file\n");
                FILE *fptr2=fopen("file2.txt","w");
                if(fptr2==NULL) printf("cannot open file\n");
                int size;
                printf("Enter the size you want copy: ");
                scanf("%d", &size);
                start=clock();
                copy_by_block(fptr1,fptr2,size);
                end=clock();
                printf("Time is %f\n", (double)(end-start)/CLOCKS_PER_SEC);
                fclose(fptr1);
                fclose(fptr2);
            };
            break;
            default:
            break;
        }
    }while(opt!=4);
    return 0;
}