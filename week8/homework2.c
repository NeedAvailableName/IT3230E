//write a program that convert a number from decimal system to binary system using recursion 
#include<stdio.h> 
long convert(int num) {
    if(num == 0) return 0;
    else return (num % 2 + 10 * (convert(num / 2)));
}
int main() {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Convert to binary: %ld", convert(num));
    return 0;
}