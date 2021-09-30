#include<stdio.h>
#include<stdlib.h>
typedef struct phoneaddress_t{
    char name[20];
    char tel[11];
    char email[25];
}phoneaddress;
int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Wrong number of arguments\n");
        printf("Correct syntax: <./fileread> <filename>\n");
        return 0;
    }
    FILE *f;
    if( (f = fopen(argv[1], "r+b")) == NULL){
        printf("Cannot open %s", argv[1]);
        return 0;
    }
    phoneaddress *phonearr;
    phonearr = (phoneaddress*)malloc(sizeof(phoneaddress));
    printf("%-20s %-12s %-25s\n", "Name", "Phone", "Email");
    while(!feof(f)){
        if(fread(phonearr, sizeof(phoneaddress), 1, f) != 0)
            printf("%-20s %-12s %-25s\n", phonearr->name, phonearr->tel, phonearr->email);
    }
    fclose(f);
    free(phonearr);
}