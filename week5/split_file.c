#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[20];
    char tel[11];
    char email[25];
} contact;
int main(int argc, char *argv[]){
    if(argc != 5){
        printf("Wrong number of arguments!\n");
        printf("Correc syntax: .\filesplit filename number file1 file2\n");
        return 0;
    }
    FILE *fptr = fopen(argv[1], "r+b");
    if(fptr == NULL) {
        printf("Cannot open %s\n", argv[1]);
        return 0;
    }
    FILE *fptr1 = fopen(argv[3], "w+b");
    if(fptr1 == NULL) {
        printf("Cannot open %s\n", argv[3]);
        return 0;
    }
    FILE *fptr2 = fopen(argv[4], "w+b");
    if(fptr2 == NULL) {
        printf("Cannot open %s\n", argv[4]);
        return 0;
    }
    int num = atoi(argv[2]);
    contact *s;
    s = (contact *)malloc(num * sizeof(contact));
    if(fread(s, sizeof(contact), num, fptr) == 0) {
        printf("Failed to split due to input number\n");
        return 0;
    }
    fwrite(s, sizeof(contact), num, fptr1);
    realloc(s, sizeof(contact));
    while(!feof(fptr)) {
        if(fread(s, sizeof(contact), 1, fptr) != 0) {
            fwrite(s, sizeof(contact), 1, fptr2);
        } 
    }
    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);
    free(s);
}