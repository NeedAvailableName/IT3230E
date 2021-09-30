/*#include<stdio.h>
int n, k, count = 0;
int a[100];
void printSolution() {
    for (int i = 1; i <= k; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void Try(int m) {
    int j;
    for(j = a[m-1] + 1; j <= n-k+m; j++) {
        a[m] = j;
        if(m == k) count++;
        else Try(m+1);
    }
}
int main() {
    scanf("%d", &k);
    scanf("%d", &n);
    a[0] = 0;
    printf("%d", count);
}*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    printf("%d", sum);
    return 0;
}