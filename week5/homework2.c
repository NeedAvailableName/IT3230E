/*Gather information about iphone, samsung, oppo.. smartphones on the web and 
write to the file PhoneDB.txt in the following format 
(each line corresponds a phone model, the file needs to contain at least 20 phone models).
Model Memory Space(GB) Screen Size(inches) Price
Write a program that the menu interface as follows:
1. Import DB from text: automatically converts PhoneDB.txt to PhoneDB.dat 
using dynamically allocated memory.
2. Imprort from DB: Read from file .dat into memory.
Support full reading mode and partial reading from the beginning of the file or the end of the file 
(the user enters the number of records to read and the starting position).
3. Print all database: read data from PhoneDB.dat to the screen. 
If there are more than on screen, pagination is required.
4. Search by phone by Phone Model.
5. Exit*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define n 20
typedef struct {
    char model[40];
    char memory[10];
    char screen[10];
    char price[10];
} phone;
phone *s;
int length = n;
void func1(FILE *fptr1, FILE *fptr2) {
    s = (phone *)malloc(sizeof(phone));
    while (fscanf(fptr1, "%s %s %s %s\n", s->model, s->memory, s->screen, s->price) != EOF)
        fwrite(s, sizeof(phone), 1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
    free(s);
}

void fullread(FILE *fptr2) {
    s = (phone *)malloc(n * sizeof(phone));
    fread(s, sizeof(phone), n, fptr2);
    fclose(fptr2);
}

void partread(FILE *fptr2, int num, int pos) {
    s = (phone *)malloc(num * sizeof(phone));
    fseek(fptr2, (pos-1) * sizeof(phone), SEEK_SET);
    fread(s, sizeof(phone), num, fptr2);
    fclose(fptr2);
}

void func2(FILE *fptr2) {
    int option;
    printf("1.Full-reading mode\n");
    printf("2.Partial-reading mode\n");
    scanf("%d", &option);
    switch (option) {
    case 1: 
        fullread(fptr2);
        break;
    case 2: {
        int pos, num;
        printf("Enter the position and the number of record: ");
        scanf("%d %d", &pos, &num);
        partread(fptr2, num, pos);
        length = num;
    }
    break;
    default:
        break;
    }
}

void func3() {
    int j = length;
    printf("%-30s %-20s %-20s %-10s\n", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    for(int i = 0; i < j; i ++) {
        if((i + 1) % 25 == 0) {
            printf("End of page %d\n", (i + 1) / 25);
            char c;
            do {
                printf("Move to next page? (Y/N) ");
                scanf(" %c", &c);
            } while(c != 'Y' && c != 'N');
            if(c == 'N')
                return;
        }
        printf("%-30s %-20s %-20s %-10s\n", s[i].model, s[i].memory, s[i].screen, s[i].price);
    }
}

void func4() {
    int i, k=0;
    char model[40];
    printf("Enter the phone model for searching: ");
    gets(model);
    for (i = 0; i < n; i++) {
        if (strcmp(model, s[i].model) == 0) {
            printf("Searching result: %-30s %-20s %-20s %-10s\n", s[i].model, s[i].memory, s[i].screen, s[i].price);
            k++;
        }
    }
    if(k==0) {
        printf("No result\n");
    }
}

int main() {
    int opt;
    do {
        printf("MENU\n");
        printf("1. Import from text to file .dat\n");
        printf("2. Read from file .dat to memory\n");
        printf("3. Read database to screen\n");
        printf("4. Search phone\n");
        printf("5. Exit\n");
        printf("Enter a option: ");
        scanf("%d", &opt);
        fflush(stdin);
        switch(opt) {
            case 1: {
                FILE *fptr1 = fopen("PhoneDB.txt", "r");
                if (fptr1 == NULL)
                    printf("cannot open file\n");
                FILE *fptr2 = fopen("PhoneDB.dat", "w+b");
                if (fptr2 == NULL)
                    printf("cannot open file\n");
                func1(fptr1, fptr2);
            }
            break;
            case 2: {
                FILE *fptr2 = fopen("PhoneDB.dat", "r+b");
                if (fptr2 == NULL) {
                    printf("cannot open file\n");
                }    
                func2(fptr2);
            }
            break;
            case 3: func3();    
            break;
            case 4: func4();
            break;
            case 5: printf("Exit\n");
            break;
            default:
            break;
        } 
    } while(opt != 5);
    return 0;
}