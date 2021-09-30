#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
typedef struct{
    char Model[40];
    char memo[10];
    char screen[5];
    char price[10];
}phoneDB_t;
phoneDB_t *phoneDB;
int total = MAX;

void op1(FILE *f1, FILE *f2){
    phoneDB = (phoneDB_t*)malloc(sizeof(phoneDB_t));
    for(int i = 0; i < MAX; i++){
        fscanf(f1, "%s %s %s %s", phoneDB->Model, phoneDB->memo, phoneDB->screen, phoneDB->price);
        fwrite(phoneDB, sizeof(phoneDB_t), 1, f2);
    }
    fclose(f1);
    fclose(f2);
    free(phoneDB);
}
void fullread(FILE *f){
    phoneDB = (phoneDB_t*)malloc(MAX * sizeof(phoneDB_t));
    fread(phoneDB, sizeof(phoneDB_t), MAX, f);
    total = MAX;
    fclose(f);
}
void partread(FILE *f, int len, int begin){
    if (len > MAX - begin + 1) 
        len = MAX - begin + 1;
    phoneDB = (phoneDB_t*)malloc(len * sizeof(phoneDB_t));
    if(phoneDB == NULL || len == 0){
        printf("Memory allocation failed\n");
        return;
    }
    if(fseek(f, (begin - 1) * sizeof(phoneDB_t), SEEK_SET) != 0 || begin > MAX){
        printf("Cannot find records!\n");
        return;
    }
    fread(phoneDB, sizeof(phoneDB_t), len, f);
    total = len;
    fclose(f);
}
void op2(FILE *f){
    int menu;
    int begin;
    int len;
    printf("\n1. Full reading mode\n");
    printf("2. Partial reading mode\n");
    printf("\nEnter choice: ");
    scanf("%d", &menu);
    switch(menu){
        case 1: 
            fullread(f);
            break;
        case 2:
            printf("Enter number of records and starting position: ");
            scanf("%d %d", &len, &begin);
            partread(f, len, begin);
            break;
        default:
            break;
    }

}
void op3(){
    int len = total;
    printf("\n%-30s %-20s %-20s %-10s\n", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    for(int i = 0; i < len; i ++){
        if((i + 1) % 25 == 0){
            printf("\nEnd of page %d\n", (i + 1) / 25);
            char c;
            do{
                printf("Continue to next page? (Y/N) ");
                scanf(" %c", &c);
            }while(c != 'Y' & c != 'N');

            if(c == 'N')
                return;
            
            printf("\n%-30s %-20s %-20s %-10s\n", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
        }
        printf("%-30s %-20s %-20s %-10s\n", phoneDB[i].Model, phoneDB[i].memo, phoneDB[i].screen, phoneDB[i].price);
    }
}
void op4(){
    char str[40];
    printf("Enter phone model: ");
    scanf("%s", str);
    int check = 0;
    for(int i = 0; i < total; i ++){
        if(strstr(phoneDB[i].Model, str) != NULL){
            if(check == 0)
                printf("%-30s %-20s %-20s %-10s\n", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
            printf("%-30s %-20s %-20s %-10s\n", phoneDB[i].Model, phoneDB[i].memo, phoneDB[i].screen, phoneDB[i].price);
            check ++;
        }
    }
    if(check == 0)
        printf("Cannot find %s\n", str);
}
void printmenu(){
    printf("\nMENU\n");
    printf("1. Import DB from text\n");
    printf("2. Import from DB\n");
    printf("3. Print All Database\n");
    printf("4. Search by phone by Phone Model\n");
    printf("5. Exit\n");
    printf("\nEnter choice: ");
}
int main(){
    FILE *f1, *f2, *f;
    int menu;
    do{
        printmenu();
        scanf("%d", &menu);
        switch(menu){
            case 1:
                if( (f1 = fopen("phoneDB.txt", "r")) == NULL){
                    printf("Cannot open phoneDB.txt\n");
                    return 0;
                }
                if( (f2 = fopen("phoneDB.dat", "w+b")) == NULL){
                    printf("Cannot open phoneDB.dat\n");
                    return 0;
                }
                op1(f1, f2);
                break;
            case 2:
                if( (f = fopen("phoneDB.dat", "r+b")) == NULL){
                    printf("Cannot open phoneDB.dat\n");
                    return 0;
                }
                op2(f);
                break;
            case 3:
                op3();
                break;
            case 4:
                op4();
                break;
            default:
                break;
        }
    }while(menu != 5);
    
}