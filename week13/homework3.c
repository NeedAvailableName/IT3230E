/*From unsorted PhoneDB.dat sort the data by the field of phone model 
using Heapsort and display the result int the screen*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char model[40];
    char memo[10];
    char screen[5];
    int price;
}phone;
void adjust(phone list[], int root, int n) {
    int child;
    char rootkey[40];
    phone temp;
    temp = list[root];
    strcpy(rootkey, list[root].model);
    child = 2 * root;
    while(child <= n) {
        if((child < n) && (strcmp(list[child].model, list[child+1].model) < 0)) child++;
        if(strcmp(rootkey, list[child].model) > 0) break;
        else {
            list[child/2] = list[child];
            child *= 2;
        }
    }
    list[child/2] = temp;
}
void heapsort(phone list[], int n) {
    int i, j;
    phone temp;
    for(i = n/2; i > 0; i--) adjust(list, i , n);
    for(i = n-1; i > 0; i--) {
        temp = list[1];
        list[1] = list[i+1];
        list[i+1] = temp;
        adjust(list, 1, i);
    }
}
int main() {
    phone a[30];
    int i, count = 1;
    FILE *fptr2 = fopen("PhoneDB.dat", "r+b");
    if(fptr2 == NULL) printf("cannot open file\n");
    phone *s = (phone *)malloc(sizeof(phone));
    while(!feof(fptr2)) {
        fread(s, sizeof(phone), 1, fptr2);
        strcpy(a[count].model, s->model);
        strcpy(a[count].memo, s->memo);
        strcpy(a[count].screen, s->screen);
        a[count].price = s->price;
        count++;
    }
    heapsort(a, count);
    printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    for(i = 1; i < count-1; i++) {
        printf("%-3d %-30s %-20s %-20s %-10d\n", i, a[i].model, a[i].memo, a[i].screen, a[i].price);
    }
    free(s);
    fclose(fptr2);
    return 0;
}