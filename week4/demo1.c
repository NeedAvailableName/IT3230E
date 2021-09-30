#include<stdlib.h>
#include<stdio.h>
int main() {
    int i,n,*p;
    printf("How many numbers do you want to enter:");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    if(p==NULL) {
        printf("Memory allocation is falled\n");
        return 1;
    }
    printf("enter the number: ");
    for(i=0;i<n;i++) {
        scanf("%d", &p[i]);
    }
    printf("reverse order:\n");
    for(i=n-1;i>=0;i--) {
        printf("%d ", p[i]);
    }
    free(p);
    return 0;
}