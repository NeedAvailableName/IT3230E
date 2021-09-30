#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char Model[40];
    char memo[10];
    char screen[5];
    float price;
}phoneDB_t;
phoneDB_t *phoneDB;
int total = 0;
struct list_el{
    phoneDB_t data;
    struct list_el *next;
};
typedef struct list_el node_addr;
node_addr *root, *cur, *prev;

phoneDB_t *enterAddr(){
    phoneDB_t *new;
    new = (phoneDB_t*)malloc(sizeof(phoneDB_t));
    fflush(stdin);
    printf("Enter model: ");
    scanf("%s", new->Model);
    printf("Enter memory: ");
    scanf("%s", new->memo);
    printf("Enter screen size: ");
    scanf("%s", new->screen);
    printf("Enter price ($): ");
    scanf("%f", &new->price);
    return new;
}

phoneDB_t *phoneData(node_addr *t){
    phoneDB_t *temp;
    temp = (phoneDB_t*)malloc(sizeof(phoneDB_t));
    strcpy(temp->Model, t->data.Model);
    strcpy(temp->memo, t->data.memo);
    strcpy(temp->screen, t->data.screen);
    temp->price = t->data.price;
    return temp;
}

node_addr *makeNewNode(phoneDB_t data){
    node_addr *new = (node_addr*)malloc(sizeof(node_addr));
    strcpy(new->data.Model, data.Model);
    strcpy(new->data.memo, data.memo);
    strcpy(new->data.screen, data.screen);
    new->data.price = data.price;
    new->next = NULL;
    return new;
}

void insertAfterCurrent(phoneDB_t e){     //Current pointer move to the next node
    node_addr *new = makeNewNode(e);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
    }else{
        new->next = cur->next;
        cur->next = new;
        prev = cur;
        cur = new;
    }
}

void insertBeforeCurrent(phoneDB_t e){    //Current pointer is unchanged
    node_addr *new = makeNewNode(e);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
    }else{
        prev->next = new;
        new->next = cur;
        prev = new;
    }
}

void insertAtHead(phoneDB_t e){           //Current pointer move to root
    node_addr *new = makeNewNode(e);
    new->next = root;
    root = new;
    cur = root;
    prev = NULL;
}

void freeAll(){
    node_addr *temp;
    temp = root;
    while(temp != NULL){
        free(temp);
        root = root->next;
        temp = root;
    }
}

void reverseList(){
    cur = NULL;
    prev = NULL;
    while(root != NULL){
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    root = prev;
}
void op1(FILE *f){
    root = NULL;
    cur = root;
    prev = NULL;
    int i = 0;
    phoneDB = (phoneDB_t*)malloc(sizeof(phoneDB_t));
    while(!feof(f)){
        fscanf(f, "%s %s %s %f", phoneDB->Model, phoneDB->memo, phoneDB->screen, &phoneDB->price);
        insertAtHead(*phoneDB);
        i ++;
    }
    free(phoneDB);
    total = i;
}

void op2(FILE *f){
    root = NULL;
    cur = root;
    prev = NULL;
    int i = 0;
    phoneDB = (phoneDB_t*)malloc(sizeof(phoneDB_t));
    while(fread(phoneDB, sizeof(phoneDB_t), 1, f) != 0){
        insertAfterCurrent(*phoneDB);
        i ++;
    }
    free(phoneDB);
    total = i;
}

void op3(){
    node_addr *temp;
    int i = 0;
    printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)\n");
    for(temp = root; temp != NULL; temp = temp->next){
        i ++;
        printf("%-3d %-30s %-20s %-20s %-6.3f\n", i, temp->data.Model, temp->data.memo, temp->data.screen, temp->data.price);
    }
    free(temp);
}

void op4(){
    char *name;
    name = (char*)malloc(40);
    printf("Enter phone model: ");
    scanf("%s", name);
    node_addr *temp;
    int check = 0;
    for(temp = root; temp != NULL; temp = temp->next){
        if(strstr(temp->data.Model, name) != NULL){
            check ++;
            if(check == 1)
                printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)\n");
            printf("%-3d %-30s %-20s %-20s %-6.3f\n", check, temp->data.Model, temp->data.memo, temp->data.screen, temp->data.price);
        }
    }
    if(check == 0)
        printf("Cannot found phone model\n");
    free(name);
    free(temp);
}

void op5(){
    float p;
    printf("Enter price ($): ");
    scanf("%f", &p);
    node_addr *temp;
    int check = 0;
    for(temp = root; temp != NULL; temp = temp->next){
        if(temp->data.price <= p){
            check ++;
            if(check == 1)
                printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)\n");
            printf("%-3d %-30s %-20s %-20s %-6.3f\n", check, temp->data.Model, temp->data.memo, temp->data.screen, temp->data.price);
        }
    }
    if(check == 0)
        printf("Cannot found any satisfied phone\n");
    free(temp);
}  
    
void op6(FILE *f){
    node_addr *temp;
    for(temp = root; temp != NULL; temp = temp->next){
        fwrite(phoneData(temp), sizeof(phoneDB_t), 1, f);
    }
    free(temp);
    fclose(f);
}

void op7(){
    printf("Enter current position: ");
    int c;
    scanf("%d", &c);
    node_addr *temp, *pretemp;
    int i = 0;
    for(temp = root; temp != NULL; temp = temp->next){
        i ++;
        if(i == c){
            prev = pretemp;
            cur = temp;
            break;
        }
        pretemp = temp;
    }
    printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)\n");
    printf("%-3d %-30s %-20s %-20s %-6.3f\n", i, temp->data.Model, temp->data.memo, temp->data.screen, temp->data.price);
    int choice;
    do{
        printf("\n1. Input before current position.\n");
        printf("2. Input after current position.\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertBeforeCurrent(*enterAddr());
            break;
        
        default:
            insertAfterCurrent(*enterAddr());
            break;
        }
    }while(choice != 1 && choice != 2);
    free(temp);
    free(pretemp);
}

void printMenu(){
    printf("\n----------------MENU--------------\n");
    printf("1. Import from text.\n");
    printf("2. Import from dat.\n");
    printf("3. Display list.\n");
    printf("4. Search by phone by phone model.\n");
    printf("5. Search phone below price.\n");
    printf("6. Export to dat.\n");
    printf("7. Manual Insertion.\n");
    printf("8. Exit.\n");
    printf("\nEnter choice: ");
}
int main(){
    int menu;
    FILE *f1, *f2;
    do{
        printMenu();
        scanf("%d", &menu);
        switch (menu){
            case 1:
                if( (f1 = fopen("phoneDB.txt", "r")) == NULL){
                    printf("Cannot open %s\n", "phoneDB.txt");
                    return 0;
                }
                op1(f1);
                break;

            case 2:
                if( (f2 = fopen("phoneDB.dat", "r + b")) == NULL){
                    printf("Cannot open %s\n", "phoneDB.dat");
                    return 0;
                }
                op2(f2);
                break;

            case 3:
                op3();
                break;

            case 4: 
                op4();
                break;

            case 5:
                op5();
                break;

            case 6:
                if( (f2 = fopen("phoneDB.dat", "w + b")) == NULL){
                    printf("Cannot open %s\n", "phoneDB.dat");
                    return 0;
                }
                op6(f2);
                break;

            case 7:
                op7();
                break;

            default:
                break;
        }
    }while(menu != 8);
}