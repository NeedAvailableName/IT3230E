#include"DLL.h"
int main() {
    int opt;
    do {
        printf("1. Read file\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr = fopen("", "r");
                if(fptr == NULL) printf("cannot open file\n");
                while(!feof(fptr)) {
                    elementType *s = (elementType *)malloc(sizeof(elementType));
                    free(s);
                }
                fclose(fptr);
            }
            break;
            case 2: {}
            break;
            case 3: {}
            break;
            case 4: {}
            break; 
            case 5: {}
            break;
        }
    }while(opt != 5);
    return 0;
}