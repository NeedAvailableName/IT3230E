#include<stdio.h>
int n;
int a[10000];
void printSolution() {
    int i, j;
    for(i = 1; i <= n; i++) {
        j = a[i];
        printf("%d", j);
    }
    printf("\n");
}
void Try(int k) {
    for(int j = 0; j <= 1; j++) {
        a[k] = j;
        if(k == n) printSolution();
        else Try(k+1);
    }
}
int main() {
    scanf("%d", &n);
    Try(1);
}
