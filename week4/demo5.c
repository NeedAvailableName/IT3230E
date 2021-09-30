#include<stdio.h>
#include<stdlib.h>
#define SIZE 80
typedef struct {
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;
phoneaddress a[SIZE];
int main() {
    int i,n,num;
    printf("How many record? ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("enter the name of record %d ", i+1);
        scanf("%s", &a[i].name);
        printf("Enter the tel of record %d ", i+1);
        scanf("%s", &a[i].tel);
        printf("Enter the email of record %d ", i+1);
        scanf("%s", a[i].email);
    }
    FILE *fptr=fopen("phoneaddress.dat","w+b");
    if(fptr==NULL) printf("cannot open file\n");
    num=fwrite(a,sizeof(phoneaddress),n,fptr);
    printf("%d\n", num);
    fptr=fopen("phoneaddress.dat","rb");
    if(fptr==NULL) printf("cannot open file\n");
    num=fread(a,sizeof(phoneaddress),n,fptr);
    printf("Name\tTel\tEmail\n");
    for(i=0;i<n;i++) {
        printf("%s\t%s\t%s\n", a[i].name, a[i].tel, a[i].email);
    }
    fclose(fptr);
    return 0;
}