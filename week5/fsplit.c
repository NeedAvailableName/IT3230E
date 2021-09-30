#include<stdio.h>
#include<stdlib.h>
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int main(int argc, char *argv[]){
    if(argc != 5){
        printf("Wrong number of arguments!\n");
        printf("Correc syntax: <./filesplit> <filename> <number> <file1> <file2>\n");
        return 0;
    }
    FILE *f, *f1, *f2;
    if( (f = fopen(argv[1], "r+b")) == NULL){
        printf("Cannot open %s\n", argv[1]);
        return 0;
    }
    if( (f1 = fopen(argv[3], "w+b")) == NULL){
        printf("Cannot open %s\n", argv[3]);
        return 0;
    }
    if( (f2 = fopen(argv[4], "w+b")) == NULL){
        printf("Cannot open %s\n", argv[4]);
        return 0;
    }
    int len = atoi(argv[2]);
    phoneaddress *phonearr;
    phonearr = (phoneaddress*)malloc(len * sizeof(phoneaddress));
    if(fread(phonearr, sizeof(phoneaddress), len, f) == 0){
        printf("Failed to split due to input number\n");
        return 0;
    }
    fwrite(phonearr, sizeof(phoneaddress), len, f1);
    realloc(phonearr, sizeof(phoneaddress));
    while(!feof(f)){
        if(fread(phonearr, sizeof(phoneaddress), 1, f) != 0)
            fwrite(phonearr, sizeof(phoneaddress), 1, f2);
    }
    fclose(f);
    fclose(f1);
    fclose(f2);
    free(phonearr);
}