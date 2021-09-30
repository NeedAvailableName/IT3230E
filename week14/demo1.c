#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char name[40];
    char phone[10];
    char email[40];
} phoneaddress;
void quicksort(phoneaddress list[], int left, int right) {
    int i, j;
    char pivot[40];
    phoneaddress temp;
    if(left < right) {
        i = left;
        j = right+1;
        strcpy(pivot, list[left].name);
        do {
            do i++;
            while(strcmp(list[i].name, pivot) < 0);
            do j--;
            while(strcmp(list[j].name, pivot) > 0);
            if(i < j) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }while(i < j);
        temp = list[left];
        list[left] = list[j];
        list[j] = temp;
        quicksort(list, left, j-1);
        quicksort(list, j+1, right);
    }
}
int main() {
    int i, count = 0;
    FILE *fptr = fopen("phoneaddress.txt", "r");
    if(fptr == NULL) printf("cannot open file\n");
    phoneaddress *a = (phoneaddress *)malloc(sizeof(phoneaddress));
    while(!feof(fptr)) {
        fscanf(fptr, "%s %s %s", a->name, a->phone, a->email);
        count++;
    }
    quicksort(a, 0, count);
    for(i = 0; i < count; i++) {
        printf("%-40s %-10s %-40s\n", a[i].name, a[i].phone, a[i].email);
    }
    free(a);
    return 0;
}