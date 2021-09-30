#include<stdio.h>
enum{SUCCESS, FAIL};
main(void) {
    FILE*fptr;
    char filename[]="haiku.txt";
    int reval=SUCCESS;
    if((fptr=fopen(filename,"r"))==NULL) {
        printf("cannot open %s\n", filename);
        reval=FAIL;
    }
    else {
        printf("the value of fptr:0x%p\n", fptr);
        printf("ready to close the file");
        fclose(fptr);
    }
    return reval;
}
