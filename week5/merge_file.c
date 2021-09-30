#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[20];
    char tel[11];
    char email[25];
} contact;
int main(int argc, char *argv[]){
    if(argc != 4){
        printf("Wrong syntax\n");
        printf("Correc syntax: .\filemerge filename file1 file2\n");
        return 0;
    }
    FILE *fptr = fopen(argv[1], "wb");
    if(fptr == NULL) {
        printf("Cannot open %s\n", argv[1]);
        return 0;
    }
    FILE *fptr1 = fopen(argv[2], "r+b");
    if(fptr1 == NULL) {
        printf("Cannot open %s\n", argv[2]);
        return 0;
    }
    FILE *fptr2 = fopen(argv[3], "r+b");
    if(fptr2 == NULL) {
        printf("Cannot open %s\n", argv[3]);
        return 0;
    }
    contact *s;
    s = (contact *)malloc(sizeof(contact));
    while(!feof(fptr1) && !feof(fptr2)) {
        if(fread(s, sizeof(contact), 1, fptr1) != 0) {
            fwrite(s, sizeof(contact), 1, fptr);
        }
        if(fread(s, sizeof(contact), 1, fptr2) != 0) {
            fwrite(s, sizeof(contact), 1, fptr);
        }
    }
    fclose(fptr);
    fclose(fptr1);
    fclose(fptr2);
    free(s);
}