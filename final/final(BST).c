#include"BST.h"
int main() {
    TreeType root;
    makeNullTree(&root);
    int opt;
    do {
        printf("1. Import from file\n");
        printf("2. Display to screen\n");
        printf("3. ");
        printf("4. ");
        printf("5. ");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr = fopen("", "r");
                if(fptr == NULL) printf("cannot open file\n");
                while(!feof(fptr)) {
                    KeyType *s = (KeyType *)malloc(sizeof(KeyType));
                    insertNode(*s, &root);
                    free(s);
                    fclose(fptr);
                }
            }
            break;
            case 2: {
            }
            break;
            case 3: {}
            break;
            case 4: {}
            break;
            case 5: {}
            break;
            case 6: {}
            break;
        }
    } while(opt != 6);
    return 0;
}