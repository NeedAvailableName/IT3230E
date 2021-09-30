/*write a program named mycat that read and display on the screen the content of a given file.
The command can take 1 or 2 arguments
cat <filename>: display content to the end
cat <filename> -p: view page by page*/
#include<stdio.h>
#define SIZE 100
int main(int argc, char *argv[]) {
    char s[SIZE];
    int count=0;
    argv[1]="file1.txt";
    FILE *fptr=fopen(argv[1],"r");
    if(argc==2) {
        while(fgets(s,SIZE,fptr)!=NULL) {
            printf("%s\n",s);
        }
        fclose(fptr);
    }
    else if(argc==3) {
        argv[2]="-p";
        while(fgets(s,SIZE,fptr)!=NULL) {
            printf("%s\n",s);
            count++;
            if(count%25==0) printf("\nNEW PAGE\n\n");
            }
            fclose(fptr);
        }
    else {
        printf("wrong syntax\n");
        printf("enter mycat filename (-p)\n");
    }
    return 0;
}