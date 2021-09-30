/*Summary of the functionalities of the PhoneDB exercises(single LL & double LL)
1. Import from PhoneDB.dat (insertAfter)
2. Display (traverse)
3. Add new phone (insertBefore/After/AtFirst/Append)
4. Insert at position
5. Delete at position
6. Delete current
7. Delete first
8. Delete last
9. Search and update: (search by model-update all field of information)
10. Reversse list
11. Save to file
12. Quit (free)*/

#include"DLL.h"

/*typedef struct {
    char model[40];
    char memory[10];
    char screen[10];
    long price;
} phone;*/

int main() {
    doublelist *root = NULL;
    doublelist *cur = NULL;
    doublelist *tail = NULL;
    int opt;
    do {
        printf("\n");
        printf("1. Import from PhoneDB.dat (insertAfterCurrent)\n");
        printf("2. Display (traverse)\n");
        printf("3. Add new phone (insertBefore/After/AtFirst/Append)\n");
        printf("4. Insert at position\n");
        printf("5. Delete at position\n");
        printf("6. Delete current phone\n");
        printf("7. Delete first phone\n");
        printf("8. Delete last phone\n");
        printf("9. Search and update\n");
        printf("10. Reverse list\n");
        printf("11. Save to file\n");
        printf("12. Quit (free)\n");
        printf("Enter the option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1: {
                //Import from PhoneDB.dat (insertAfterCurrent)
                FILE *fptr2 = fopen("PhoneDB.dat", "w+b");
                if(fopen == NULL) printf("cannot open file\n");
                elementtype *s = (elementtype *)malloc(sizeof(elementtype));
                while(fread(s, sizeof(elementtype), 1, fptr2) != 0) {
                    elementtype tmp;
                    insertAfterCurrent(tmp); 
                    //strcpy(tmp.model, s->model);
                    //strcpy(tmp.memory, s->memory);
                    //strcpy(tmp.screen, s->screen);
                    //tmp.price = s->price;
                }
                fclose(fptr2);
                free(s);
                printf("Successful\n");
            }
            break;
            case 2: {
                //Display (traverse)
                traversingList(&root, &tail);
            }
            break;
            case 3: {
                int choice;
                do {
                    printf("\n");
                    printf("1. Insert before current\n");
                    printf("2. Insert after current\n");
                    printf("3. Insert at head\n");
                    printf("4. Append\n");
                    printf("5. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1: {
                            elementtype tmp;
                            tmp = enterPhone();
                            insertBeforeCurrent(tmp);
                            printf("Successful\n");
                        }
                        break;
                        case 2: {
                            elementtype tmp;
                            tmp = enterPhone();
                            insertAfterCurrent(tmp);
                            printf("Successful\n");
                        }
                        break;
                        case 3: {
                            elementtype tmp;
                            tmp = enterPhone();
                            insertAtHead(tmp, &root, &tail, &cur);
                            printf("Successful\n");
                        }
                        break;
                        case 4: {
                            elementtype tmp;
                            tmp = enterPhone();
                            append(tmp);
                            printf("Successful\n");
                        }
                        break;
                        default:
                        break;
                    }
                } while(choice != 5);
            }
            break;
            case 4: {
                //Insert at position
                int pos;
                elementtype tmp;
                tmp = enterPhone();
                insertAtPosition(tmp, pos, &root, &tail, &cur);
                printf("Successful\n");
            }
            break;
            case 5: {
                //Delete at position
                int pos;
                deleteAtPosition(pos, &root, &tail, &cur);
                printf("Successful\n");
            }
            break;
            case 6: {
                //Delete current phone
                deleteCurrentElement();
            }
            break;
            case 7: {
                //Delete first phone
                deleteFirstElement();
                printf("Successful\n");
            }
            break;
            case 8: {
                //Delete last element
                deleteAtLast();
                printf("Successful\n");
            }
            break;
            case 9: {
                char model[40];
                int k = 0;
                //Search and update
                printf("Enter the model: ");
                fflush(stdin);
                gets(model);
                for(*cur = *root; *cur != NULL; *cur = (*cur)->next) {
                    if(strcmp(model, (*cur)->element.Model) == 0) {
                        displayNode(cur);
                        k++;
                    }
                }
                if (k == 0) printf("No result\n");
            }
            break;
            case 10: {
                //Reverse list
                reverseList(&root, &tail, &cur);
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
                freeAll(&root, &tail, &cur);
                printf("Exit\n");
            }
            break;
            default:
            break;
        }
    } while(opt != 12);
}