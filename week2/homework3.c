/*write a program that appends the content of file2 to the end of file1.
Assume that file are existing already.
Syntax: apd <file1> <file2>
Attention: check syntax - help user..*/
#include<stdio.h>
int main(int argc, char *argv[]) {
	if(argc!=3) {
		printf("wrong syntax\n");
		printf("enter apd file1 file2\n");
		return 1;
	}
	argv[1]="a1.txt";
	argv[2]="a2.txt";
	FILE *fptr1=fopen(argv[1], "a");
	FILE *fptr2=fopen(argv[2], "r");
	char c;
	while((c=fgetc(fptr2))!=EOF) {
		fputc(c,fptr1);
	}
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
