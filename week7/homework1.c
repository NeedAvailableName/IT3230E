/*Summary of the functionalities of the PhoneDB exercises(single LL & double LL)
1. Import from PhoneDB.dat (insertAfter)
2. Display (traverse)
3. Add new phone (insertBefore/After)
4. Insert at position
5. Delete at position
6. Delete current
7. Delete first
8. Search and update: (search by model-update all field of information)
9. Divide and extract (split): Output is the content of two sublists
10. Reversse list
11. Save to file
12. Quit (free)*/
//#include<stdio.h>
//#include<stdlib.h>
#include"genSLL.h"

int main() {
    int opt;
    do {
        printf("1. Import from PhoneDB.dat (insertAfterCurrent)\n");
        printf("2. Display (traverse)\n");
        printf("3. Add new phone (insertBeforeCurrent/insertAfterCurrent)\n");
        printf("4. Insert at position\n");
        printf("5. Delete at position\n");
        printf("6. Delete current phone\n");
        printf("7. Delete first phone\n");
        printf("8. Search and update\n");
        printf("9. Divide and extract (split)\n");
        printf("10. Reverse list\n");
        printf("11. Save to file\n");
        printf("12. Quit (free)\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                //Import from PhoneDB.dat (insertAfterCurrent)
                FILE *fptr2 = fopen("PhoneDB.dat", "rb");
                if(fopen == NULL) printf("cannot open file\n");
                s = (elementtype *)malloc(sizeof(elementtype));
                root = NULL;
                cur = root;
                prev = NULL;
                while(fread(s, sizeof(phone), 1, fptr2) != 0) {
                    phone tmp;
                    insertAfterCurrent(tmp); 
                    strcpy(tmp.model, s->model);
                    strcpy(tmp.memory, s->memory);
                    strcpy(tmp.screen, s->screen);
                    tmp.price = s->price;
                }
                free(s);
                printf("Successful\n");
            }
            break;
            case 2: {
                //Display (traverse)
                traversingList();
            }
            break;
            case 3: {
                //Add new phone (insertBeforeCurrent/insertAfterCurrent)
                int choice;
                do {
                    printf("1. Insert before current\n");
                    printf("2. Insert after current\n");
                    printf("3. Exit\n");
                    printf("Enter you choice: ");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1: {
                            elementtype tmp;
                            tmp = readNode();
                            insertBeforeCurrent(tmp);
                            printf("Successful\n");
                        }
                        break;
                        case 2: {
                            elementtype tmp;
                            tmp = readNode();
                            insertAfterCurrent(tmp);
                            printf("Successful\n");
                        }
                        break;
                        case 3: printf("Exit\n");
                        break;
                        default:
                        break;
                    }
                } while(choice != 3);
            }
            break;
            case 4: {
                //Insert at position
                int pos;
                elementtype tmp;
                insertAtPosition(tmp, pos);
                printf("Successful\n");
            }
            break;
            case 5: {
                //Delete at position
                int pos;
                deleteAtPosition(pos);
                printf("Successful\n");
            }
            break;
            case 6: {
                //Delete current phone
                deleteCurrentElement();
                printf("Successful\n");
            }
            break;
            case 7: {
                //Delete first phone
                deleteFirstElement();
                printf("Successful\n");
            }
            break;
            case 8: {
                char model[40];
                int k = 0;
                //Search and update
                printf("Enter the model: ");
                fflush(stdin);
                gets(model);
                for(cur = root; cur != NULL; cur = cur->next) {
                    if(strcmp(model, cur->element.model) == 0) {
                        displayNode(cur);
                        k++;
                    }
                }
                if (k == 0) printf("No result\n");
            }
            break;
            case 9: {
                //Divide and extract (split)
                int n1, n2;
                split(cur, n1, n2);
            }
            break;
            case 10: {
                //Reverse list
                listReverse(root);
                printf("Successful\n");
            }
            break;
            case 11: {
                //Save to file
                exportToFile();
                printf("Successful\n");
            }
            break;
            case 12: {
                //Quit (free)
                freeNode(root);
                printf("Exit\n");
            }
            break;
            default:
            break;
        }
    } while (opt != 12);
}