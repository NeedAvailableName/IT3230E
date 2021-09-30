/*write a program that encodes the text file according to the Caesar cipher taking two parameters:
file name and the addition offset
The algorithm's idea is simple as follows: if the addition offset is 3:
then the charactera will be encoded into the character behind it 3 places in ASCII code.
For example A->D, B->E
Then write a decode program with the same logic
Improve the program so that the coding is circular in the alphabet. For example A->D,...,Z->C*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 81
int main (int argc, char *argv[]) {
    char c;
    if(argc!=3) {
        printf("wrong syntax\n");
        printf("Enter file name and offset\n");
    }
    else {
        int offset=atoi(argv[2]);
        argv[1]="decode.txt";
        FILE *fptr=fopen(argv[1],"r");
        if(fptr==NULL) printf("cannot open file\n");
        else { 
            while((c=fgetc(fptr))!=EOF) {
                if('a'<=c&&c<='z') {
                    if(offset>26) offset=(offset%26);
                    if((c-offset)<'a') c='z'-(c-'a');
                    else c-=offset;
                    printf("%c", c);
                }
                else if('A'<=c&&c<='Z') {
                    if(offset>26) offset=(offset%26);
                    if((c-offset)<'A') c='Z'-(c-'A');
                    else c-=offset;
                    printf("%c", c);
                }
                else {
                    printf("%c", c);
                }
            }
        fclose(fptr);
        }
    }
    return 0;
}