#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char name[20];
    char tel[11];
    char email[25];
}contact;
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("wrong syntax\n");
        printf("enter read filename\n");
    }
    FILE *fptr;
    if( (fptr = fopen(argv[1], "r+b")) == NULL){
        printf("Cannot open file\n");
        return 0;
    }
    contact *s;
    s = (contact*)malloc(sizeof(contact));
    printf("%-20s %-12s %-25s\n", "Name", "Phone", "Email");
    while(!feof(fptr)){
        if(fread(s, sizeof(contact), 1, fptr) != 0)
            printf("%-20s %-12s %-25s\n", s->name, s->tel, s->email);
    }
    fclose(fptr);
    free(s);
}