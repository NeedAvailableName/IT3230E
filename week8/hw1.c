#include"DLL.h"
void op1(doublelist *root, doublelist *tail, doublelist *cur){
    FILE *f;
    if( (f = fopen("phoneDB.dat", "r + b")) == NULL){
        printf("Cannot open %s\n", "phoneDB.dat");
        return;
    }
    *root = NULL;
    *tail = NULL;
    *cur = NULL;
    elementtype *temp;
    temp = (elementtype*)malloc(sizeof(elementtype));
    while(fread(temp, sizeof(elementtype), 1, f) != 0)
        insertAfter(*temp, root, tail, cur);
    free(temp);
    fclose(f);
    printf("Successful\n");
}

void op2(doublelist *root, doublelist *tail){
    int choice;
    do{
        printf("1. Traverse from head.\n");
        printf("2. Traverse from tail.\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                traversingList(root, tail);
                break;
            case 2:
                traverseBackward(root, tail);
                break;
            default:
                break;
        }
    }while(choice < 1 || choice > 2);
}

void op3(doublelist *root, doublelist *tail, doublelist *cur){
    int choice;
    do{
        printf("1. Insert before current.\n");
        printf("2. Insert after current.\n");
        printf("3. Insert at head.\n");
        printf("4. Append.\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                insertBefore(enterPhone(), root, tail, cur);
                printf("Successful\n");
                break;
            case 2:
                insertAfter(enterPhone(), root, tail, cur);
                printf("Successful\n");
                break;
            case 3:
                insertAtHead(enterPhone(), root, tail, cur);
                printf("Successful\n");
                break;
            case 4:
                insertAtTail(enterPhone(), root, tail, cur);
                printf("Successful\n");
                break;
            default:
                break;
        }
    }while(choice < 1 || choice > 4);
}

void op4(doublelist *root, doublelist *tail, doublelist *cur){
    int n;
    printf("Enter position to insert: ");
    scanf("%d", &n);
    insertAtPosition(enterPhone(), n, root, tail, cur);
    printf("Successful\n");
}

void op5(doublelist *root, doublelist *tail, doublelist *cur){
    int n;
    printf("Enter position to delete: ");
    scanf("%d", &n);
    deleteAtPosition(n, root, tail, cur);
    printf("Successful\n");
}

void op6(doublelist *root, doublelist *tail, doublelist *cur){
    deleteCurrent(root, tail, cur);
    printf("Successful\n");
}

void op7(doublelist *root, doublelist *tail, doublelist *cur){
    deleteFirstNode(root, tail, cur);
    printf("Successful\n");
}

void op8(doublelist *root, doublelist *tail, doublelist *cur){
    deleteAtTail(root, tail, cur);
    printf("Successful\n");
}

void op9(doublelist *root, doublelist *tail, doublelist *cur){
    // traversingList(root);
    char *name;
    name = (char*)malloc(40);
    printf("\nEnter phone model: ");
    scanf("%s", name);
    doublelist temp;
    int i = 0, check = 0;
    for(temp = *root; temp != NULL; temp = temp->next){
        i ++;
        if(strstr(temp->element.Model, name) != NULL){
            check ++;
            if(check == 1)
                printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)");
            printf("%-3d %-30s %-20s %-20s %-6.3f\n", i, temp->element.Model, temp->element.memo, temp->element.screen, temp->element.price);
        }
    }
    free(name);
}

void op10(doublelist *root, doublelist *tail, doublelist *cur){
    reverseList(root, tail, cur);
}

void op11(doublelist *root, doublelist *tail){
    FILE *f;
    if( (f = fopen("phoneDB.dat", "w + b")) == NULL){
        printf("Cannot open %s\n", "phoneDB.dat");
        return;
    }
    doublelist temp;
    for(temp = *root; temp != NULL; temp = temp->next){
        fwrite(phoneData(temp), sizeof(phoneDB_t), 1, f);
    }
    free(temp);
    fclose(f);
    printf("Successful\n");
}

void printMenu(){
    printf("\n----------MENU----------\n");
    printf("1. Import from dat.\n");
    printf("2. Display.\n");
    printf("3. Add new phone.\n");
    printf("4. Insert at position.\n");
    printf("5. Delete at position.\n");
    printf("6. Delete current.\n");
    printf("7. Delete first.\n");
    printf("8. Delete last\n");
    printf("9. Search and update.\n");
    printf("10. Reverse list.\n");
    printf("11. Save to dat.\n");
    printf("12. Exit.\n");
    printf("\nEnter choice: ");
}

int main(){
    int menu;
    doublelist root = NULL, tail = NULL, cur = NULL;
    do{
        printMenu();
        scanf("%d", &menu);
        switch (menu){
            case 1:
                op1(&root, &tail, &cur);
                break;
            
            case 2:
                op2(&root, &tail);
                break;
                
            case 3:
                op3(&root, &tail, &cur);
                break;

            case 4:
                op4(&root, &tail, &cur);
                break;


            case 5:
                op5(&root, &tail, &cur);
                break;

            case 6:
                op6(&root, &tail, &cur);
                break;

            case 7:
                op7(&root, &tail, &cur);
                break;

            case 8:
                op8(&root, &tail, &cur);
                break;

            case 9:
                op9(&root, &tail, &cur);
                break;

            case 10:
                op10(&root, &tail, &cur);
                break;

            case 11:
                op11(&root, &tail);
                break;

            case 12:
                if(root != NULL)
                   freeAll(&root, &tail, &cur);
                break;
            
            default:
                break;
        }
    }while(menu != 12);
}