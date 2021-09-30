/*write the program named mycp that works like command cp.
It can copy a text file to another using similar syntax of cp command.
For example: mycp a1.txt a2.txt
Attention: Program must check syntax (number of parameters) - printf user guide texts..)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
	if(argc!=3) {
		printf("wrong syntax\n");
		printf("enter mycp file1 file2\n");
		return 1;
	}
	else{
		argv[1]="a1.txt";
		argv[2]="a2.txt";
		FILE *fptr1=fopen(argv[1],"w");
		FILE *fptr2=fopen(argv[2],"r");
	    if(fptr1==NULL) printf("cannot open a1.txt\n");
		if(fptr2==NULL) printf("cannot open a2.txt\n");
		char c;
		while((c=fgetc(fptr2))!=EOF) {
			fputc(c,fptr1);	
		}
		fclose(fptr1);
		fclose(fptr2);
	}
	return 0;
}
