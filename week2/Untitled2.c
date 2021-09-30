#include<stdio.h>
int main() {
    FILE*fptr1=fopen("lab1.txt","r");
    if(fptr1==NULL) printf("cannot read\n");
    char c;
    FILE*fptr2=fopen("lab1w.txt","w+");
    while(c!=EOF) {
    	c=fgetc(fptr1);
    	if('a'<=c&&c<='z') c-=32;
    	else if('A'<=c&&c<='Z') c+=32;
    	fputc(c,fptr2);
	}
    fclose(fptr1);
    fclose(fptr2);
}
