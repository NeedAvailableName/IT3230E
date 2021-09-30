#include<stdio.h>
void recurTriangle(int n, char ch) {
    int i;
    if(n > 0) {
        for(i = 0; i < n; i++) printf("%c", ch);
        printf("\n");
        recurTriangle(n-1, ch);
    }
}
int main() {
    char c = 'x';
    recurTriangle(5, c);
    return 0;
}