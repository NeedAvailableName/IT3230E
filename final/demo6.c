#include<stdio.h>
void func(int a) {
    int count = 0;
    for(int i = 2; i <= a; i++) {
        for(int j = a; j > i; j--) {
            if((a % i) == (a % j)) {
                printf("%d %d\n", i , j);
                count++;
                break;
            }
        }
        if(count == 1) break;
    }
}
int main() {
    int t;
    scanf("%d", &t);
    int a[t];
    for(int i = 0; i < t; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < t; i++) {
        func(a[i]);
    }
}