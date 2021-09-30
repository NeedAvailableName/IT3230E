/*Create phone.dat file containing at least twenty contact entries. 
Write a filesplit program that takes two parameters: 
the file name and the number of contacts you want to split, the two file names, 
and split the original file into two files.
For example with this execution the phone1.dat should includes first 10 contacts 
and phone2.dat has the rest.
filesplit phone.dat 10 phone1.dat phone2.dat*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 80
typedef struct {
    char name[SIZE];
    char phone[SIZE];
    char email[SIZE];
} contact;
int main(int argv, char *argc[]) {
    if (argv != 3) {
        printf("Wrong syntax\n");
        printf("Enter filesplit filename number\n");
    }
    else {
        int i = 1;
        int num = atoi(argc[2]);
        FILE *fptr = fopen("phone.txt", "r");
        if (fptr == NULL)
            printf("cannot open file\n");
        FILE *fptr1 = fopen("phone1.txt", "w");
        if (fptr1 == NULL)
            printf("cannot open file\n");
        FILE *fptr2 = fopen("phone2.txt", "w");
        if (fptr2 == NULL)
            printf("cannot open file\n");
        contact *s;
        s = (contact *)malloc(num * sizeof(contact));
        fwrite(s, sizeof(contact), num, fptr1);
        realloc(s, sizeof(contact));
        while (!feof(fptr)) {
            if(fread(s, sizeof(contact), 1, fptr)!=0) {
                fwrite(s, sizeof(contact), 1, fptr2);
            }
        }
        fclose(fptr);
        fclose(fptr1);
        fclose(fptr2);
        free(s);
    }
    return 0;
}