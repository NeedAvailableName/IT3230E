#include<stdio.h>
#define SIZE 100
typedef struct {
    int no;
    char name[SIZE];
    char price[SIZE];
}product;
int main() {
    product s[SIZE];
    int i=0;
    FILE *fptr=fopen("product.txt","r");
    if(fptr==NULL) printf("cannot open file\n");
    else {
        printf("No Name Price\n");
        while(fscanf(fptr, "%d %s %s\n", &s[i].no, s[i].name, s[i].price)!=EOF) {
            printf("%d %s %s\n", s[i].no, s[i].name, s[i].price);
            i++;
        }
    }
    fclose(fptr);
    return 0;
}