/*Extend the program of phone models management (PhoneDB) by implementing movetofront, transpose 
(and using counter if you can) strategies for feature Search & Update. 
Users can choose strategies and after the execution of the searching task, 
go back to the menu to diplay the Phone models list to check the effect of these strategies.*/
#include"DLL.h"

/*typedef struct {
    char model[40];
    char memory[10];
    char screen[10];
    long price;
} phone;*/

int main() {
    int opt;
    doublelist root = NULL;
    doublelist cur = NULL;
    doublelist tail = NULL;
    do {
        printf("\n");
        printf("MENU\n");
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
        switch(opt) {
            case 1: {
                //Import from PhoneDB.dat (insertAfterCurrent)
                FILE *fptr2 = fopen("PhoneDB.dat", "w+b");
                if(fopen == NULL) printf("cannot open file\n");
                elementType *s = (elementType *)malloc(sizeof(elementType));
                while(fread(s, sizeof(elementType), 1, fptr2) != 0) {
                    elementType tmp;
                    insertAfter(tmp, &root, &tail, &cur); 
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
                            elementType tmp;
                            tmp = enterPhone();
                            insertBefore(tmp, &root, &tail, &cur);
                            printf("Successful\n");
                        }
                        break;
                        case 2: {
                            elementType tmp;
                            tmp = enterPhone();
                            insertAfter(tmp, &root, &tail, &cur);
                            printf("Successful\n");
                        }
                        break;
                        case 3: {
                            elementType tmp;
                            tmp = enterPhone();
                            insertAtHead(tmp, &root, &tail, &cur);
                            printf("Successful\n");
                        }
                        break;
                        case 4: {
                            elementType tmp;
                            tmp = enterPhone();
                            insertAtTail(tmp, &root, &tail, &cur);
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
                elementType tmp;
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
                deleteCurrent(&root, &tail, &cur);
            }
            break;
            case 7: {
                //Delete first phone
                deleteFirstNode(&root, &tail, &cur);
                printf("Successful\n");
            }
            break;
            case 8: {
                //Delete last element
                deleteAtTail(&root, &tail, &cur);
                printf("Successful\n");
            }
            break;
            case 9: {
                char *model;
                model = (char *)malloc(sizeof(char));
                int choice;
                do {
                    printf("Enter the model: ");
                    fflush(stdin);
                    gets(model);
                    fflush(stdin);
                    printf("\n");
                    printf("1. Normal search\n");
                    printf("2. Move to front search\n");
                    printf("3. Transpose search\n");
                    printf("4. Exit\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1: {
                            int k = 0;
                            for(*cur = *root; cur != NULL; cur = cur->next) {
                                if(strcmp(model, cur->element.Model) == 0) {
                                    displayNode(cur);
                                    k++;
                                }
                            }
                            if (k == 0) printf("No result\n");
                        }        
                        break;
                        case 2: {
                            moveToFront(model, &root, &cur, &tail);
                        }
                        break;
                        case 3: {
                            transpose(model, &root, &cur, &tail);
                        }
                        break;
                        case 4: printf("Exit\n");
                        break;                    
                        default:
                        break;
                    }
                }while(choice != 4);
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
                //exportToFile();
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
    return 0;
}

void moveToFront(char *key, doublelist *root, doublelist *cur, doublelist *tail) {
    int k = 0;
    *cur = *root;
    while(strcmp((*cur)->element.Model, key) != 0) {
        *cur = (*cur)->next;
        k++;
    }
    if(k != 0) {
        doublelist temp = *cur;
        *cur = (*cur)->prev;
        (*cur)->next = temp->next;
        temp->next->prev = *cur;
        elementType A = temp->element;
        free(temp);
        insertAtHead(A, &root, &tail, &cur);
        displayNode(*root);
    }
    else printf("No result\n");
}
void transpose(char *key, doublelist *root, doublelist *cur, doublelist *tail) {
    int k = 0;
    *cur = *root;
    while(strcmp((*cur)->element.Model, key) != 0) {
        *cur = (*cur)->next;
        k++;
    }
    if(k != 0) {
        displayNode(*cur);
        elementType e;
        e = (*cur)->element;
        (*cur)->element = (*cur)->prev->element;
        (*cur)->prev->element = e;
    }
    else printf("No result\n");
}