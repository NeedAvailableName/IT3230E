#include<stdio.h>
#include<stdlib.h>
int main() {
    int i, n, sum = 0;
    int *ptr;
    FILE *fptr = fopen("out.txt","w");
    if(fptr==NULL) printf("cannot open file\n");
    ptr = malloc(n * sizeof(int));
    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter the number: ");
        scanf("%d", ptr[i]);
        sum+=ptr[i];
    }
    fprintf(fptr, "%d ", n);
    for(i = (n - 1); i >= 0; i--) {
        fprintf(fptr, "%d ", ptr[i]);
    }
    fprintf(fptr, "%d\n", sum);
    fclose(fptr);
    free(ptr);
    return 0;
}