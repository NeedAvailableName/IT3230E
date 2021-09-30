#include<stdio.h>
#include<stdlib.h>
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int main(int argc, char *argv[]){
    if(argc != 4){
        printf("Wrong number of arguments!\n");
        printf("Correct syntax: <./filemerge> <file1> <file2> <mergedfile>\n");
        return 0;
    }
    FILE *f1, *f2, *f;
    if( (f1 = fopen(argv[1], "r+b")) == NULL){
        printf("Cannot open %s\n", argv[1]);
        return 0;
    }
    if( (f2 = fopen(argv[2], "r+b")) == NULL){
        printf("Cannot open %s\n", argv[2]);
        return 0;
    }
    if( (f = fopen(argv[3], "wb")) == NULL){
        printf("Cannot open %s\n", argv[3]);
        return 0;
    }
    phoneaddress *phonearr;
    phonearr = (phoneaddress*)malloc(sizeof(phoneaddress));
    while(!feof(f1) || !feof(f2)){
        if(fread(phonearr, sizeof(phoneaddress), 1, f1) != 0)
            fwrite(phonearr, sizeof(phoneaddress), 1, f);
        if(fread(phonearr, sizeof(phoneaddress), 1, f2) != 0)
            fwrite(phonearr, sizeof(phoneaddress), 1, f);
    }
    fclose(f1);
    fclose(f2);
    fclose(f);
    free(phonearr);
}