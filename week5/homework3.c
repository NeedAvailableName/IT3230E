/*Write a program that transforms Vietnamese English dictionary data from text to binary form.
Ask user the begin and the end number then display the words between this range in dict.
-Miền Đất Hứa : the Promised Land
-Miến : Burma (short for Miến Điện)
-Miến Điện : Burma
-Miền Trung : Central Vietnam*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 300
void vietnamese() {
    int i;
    char string[SIZE];
    for(i = 0; i != ":"; i++) {
        return string[i];
    }
}
void english() {
    
}
typedef struct {
    char vn[SIZE];
    char eng[SIZE];
} data;
int main() {
    data *s = (data *)malloc(SIZE * sizeof(data));
    int i, begin, end;
    char string[SIZE];
    FILE *fptr1 = fopen("vnedict.txt", "r");
    if(fptr1==NULL) printf("cannot open file\n");
    FILE *fptr2 = fopen("vnedict.dat", "w+b");
    if(fptr2==NULL) printf("cannot open file\n");
    while(fgets(string, SIZE, fptr1) != NULL) {
        for(i = 0; i != ':'; i++) {
            
        }
        fwrite(s, sizeof(data), 1, fptr2);
    }
    fclose(fptr1);
    fclose(fptr2);
    free(s);

    printf("Enter the begin and the end number: ");
    scanf("%d %d", &begin, &end);
    fseek(fptr2, (begin-1) * sizeof(data), SEEK_SET);
    s = (data *)malloc((end-begin+1) * sizeof(data));
    fread(s, sizeof(data), (end-begin+1), fptr2);
    for(i = begin; i <= end; i++) {
        printf("%s : %s\n", s[i].vn, s[i].eng);
    }
    fclose(fptr2);
    free(s);
    return 0;
}