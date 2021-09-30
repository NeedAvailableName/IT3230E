 /*implement a fuction that accepts two integer arrays and returns 1 if they are equal, -1 if they are symmetric, 0 otherwise.
Write a program that accepts two arrays of integers from the user and checks for equality*/
#include<stdio.h>
#include<string.h>
#define SIZE 100
int func(char a[SIZE], char b[SIZE]) {
	gets(a);
	gets(b);
	int i,check=0, n=strlen(b);
	for(i=0;i<n;i++) {
		if(a[i]==b[i]) check++;
		else if(a[i]==b[n-i-1]) check--;
	}
	if(check==n) return 1;
	else if(check==-n) return -1;
	else return 0;
}
int main() {
	char a[SIZE], b[SIZE];
	printf("%d\n", func(a,b));
	return 0;
}
