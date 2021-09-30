#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    // char vie[50];
    // char eng[50];
    char vne[300];
}dict_t;
dict_t *dict;
// void divstr(dict_t *d, char str[]){
//     char *token;
//     char delim[2] = ":";
//     token = strtok(str, delim);
//     strcpy(d->vie, token);
//     token = strtok(NULL, delim);
//     strcpy(d->eng, token);
// }
int main(){
    FILE *f1, *f2;
    if( (f1 = fopen("VNEdict.txt", "r")) == NULL){
        printf("Cannot open %s\n", "VNEdict.txt");
        return 0;
    }
    if( (f2 = fopen("VNEdict.dat", "w+b")) == NULL){
        printf("Cannot open %s\n", "VNEdict.dat");
        return 0;
    }
    dict = (dict_t*)malloc(sizeof(dict_t));
    char *str;
    str = (char*)malloc(301);
    fgets(str, 300, f1);
    while(fgets(str, 300, f1) != NULL){
        for(int i = 0; str[i] != '\0'; i ++){
            if(str[i] == '\n'){
                str[i] = '\0';
                break;
            }
        }
        // divstr(dict, str);
        strcpy(dict->vne, str);
        fwrite(dict, sizeof(dict_t), 1, f2);
    }
    free(str);
    fclose(f1);
    fclose(f2);
    int end, begin, len;
    if( (f2 = fopen("VNEdict.dat", "r+b")) == NULL){
            printf("Cannot open %s\n", "VNEdict.dat");
            return 0;
        }
    printf("Enter begin and end number: ");
    scanf("%d %d", &begin, &end);
    if(fseek(f2, (begin - 1) * sizeof(dict_t), SEEK_SET) != 0){
        printf("Failed to find words\n");
        return 0;
    }
    len = end - begin + 1;
    dict = (dict_t*)calloc(len, sizeof(dict_t));
    if(dict == 0){
        printf("Memory allocation failed\n");
        return 0;
    }
    fread(dict, sizeof(dict_t), len, f2);
    for(int i = 0; i < len; i ++){
        // printf("%s:%s\n", dict[i].vie, dict[i].eng);
        printf("%s\n", dict[i].vne);
    }
    fclose(f2);
    free(dict);
}   