#include<stdio.h>
#include<stdlib.h>
#define SIZE 80
typedef struct {
    char name[SIZE];
    char phone[SIZE];
    char email[SIZE];
} contact;
int main() {
    int i, n;
    FILE *fptr = fopen("phone.dat", "w+b");
    printf("Enter the number of record: ");
    scanf("%d", &n);
    contact *s = malloc(n*sizeof(contact));
    for(i = 0; i < n; i++) {
        printf("Enter the name of record %d: ", i+1);
        fflush(stdin);
        gets((s+i)->name);
        fflush(stdin);
        printf("Enter the phone of record %d: ", i+1);
        gets((s+i)->phone);
        fflush(stdin);
        printf("Enter the email of record %d: ", i+1);
        gets((s+i)->email);
        fflush(stdin);
        fwrite(s, sizeof(contact), 1, fptr);
    }
    for(i = 0; i < n; i++) {
        fread(s, sizeof(contact), 1, fptr);
        printf("%s\t%s\t%s\n", (s+i)->name, (s+i)->phone, (s+i)->email);
    }
    fclose(fptr);
    free(s);
    return 0;
}