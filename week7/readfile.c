#include<stdio.h>
#include<stdlib.h>
typedef struct {
    char model[40];
    char memory[10];
    char screen[10];
    long price[10];
}phone;
int main() {
    FILE *fptr1 = fopen("PhoneDB.txt", "r");
    FILE *fptr2 = fopen("PhoneDB.dat", "w+b");
    phone *s = (phone *)malloc(sizeof(phone));
    while(!feof(fptr1)) {
        if(fread(s, sizeof(phone), 1, fptr1) != 0) {
            fwrite(s, sizeof(phone), 1, fptr2);
        }
    }
    while(!feof(fptr2)) {
    	if(fread(s, sizeof(phone), 1, fptr2) != 0) {
            printf("%-40s %-20s %-20s %-10ld\n", s->model, s->memory, s->screen, s->price);
        }
    }
    fclose(fptr1);
    fclose(fptr2);
    free(s);
    return 0;
}
