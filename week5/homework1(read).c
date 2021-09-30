/*write a fileread program to read the contents of the .dat files above 
to check the results of filesplit and filemerge.*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 80
typedef struct {
    char name[20];
    char phone[11];
    char email[25];
} contact;
int main() {
    contact *s;
    s = (contact *)malloc(sizeof(contact));
    FILE *fptr = fopen("phonebook.dat", "rb");
    if(fptr==NULL) printf("cannot open file\n");
    while(!feof(fptr)) {
        if(fread(s, sizeof(contact), 1, fptr) != 0) {
            printf("%-20s%-12s%-25s\n", s->name, s->phone, s->email);
        }   
    }
    free(s);
    fclose(fptr);
    return 0;
}