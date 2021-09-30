#include<stdio.h>
int triangle (int n) {
    if(n == 1) return 1;
    else return (n + triangle(n - 1));
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d ", triangle(n));
    return 0;
}