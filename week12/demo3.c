#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
void ThemPhanTu(int a[], int n, int val, int pos){
    // Mang da day, khong the them.
    if(n >= MAX){
        return;
    }
    // Neu pos <= 0 => Them vao dau
    if(pos < 0){
        pos = 0;
    }
    // Neu pos >= n => Them vao cuoi
    else if(pos > n){
        pos = n;
    }
    // Dich chuyen mang de tao o trong truoc khi them.
    for(int i = n; i >= pos; i--){
        a[i] = a[i-1];
    }
    // Chen val tai pos
    a[pos-1] = val;
    // Tang so luong phan tu sau khi chen.
    ++n;
}
char *name(char str[]) {
    int i = strlen(str) - 1;
    while(i >= 0 && str[i] != '_') i--;
    return str + i + 1;
}
int main() {
    int i;
    int s[] = {1, 2, 3, 4, 5};
    ThemPhanTu(s, 5, 2, 4);
    for(i = 0; i < 6; i++) {
        printf("%d ", s[i]);
    }
    char str[] = "Pham_Hai_Dang";
    printf("%s", name(str));
    return 0;
}