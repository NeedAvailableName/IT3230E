#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char Model[40];
    char memo[10];
    char screen[5];
    float price;
}phoneDB_t;
typedef phoneDB_t elementtype;
struct node_t{
    elementtype element;
    struct node_t *next;
};
typedef struct node_t node;
node *root = NULL;
node *cur = NULL;
node *prev = NULL;
int total;

node *makeNewNode(elementtype e){
    node *new = (node*)malloc(sizeof(node));
    new->element = e;
    new->next = NULL;
    return new;
}

elementtype enterPhone(){
    elementtype *phoneDB;
    phoneDB = (elementtype*)malloc(sizeof(elementtype));
    printf("Enter model: ");
    scanf("%s", phoneDB->Model);
    printf("Enter memory: ");
    scanf("%s", phoneDB->memo);
    printf("Enter screen size: ");
    scanf("%s", phoneDB->screen);
    printf("Enter price ($): ");
    scanf("%f", &phoneDB->price);
    return *phoneDB;
}

elementtype *phoneData(node *t){
    elementtype *temp;
    temp = (elementtype*)malloc(sizeof(elementtype));
    strcpy(temp->Model, t->element.Model);
    strcpy(temp->memo, t->element.memo);
    strcpy(temp->screen, t->element.screen);
    temp->price = t->element.price;
    return temp;
}

// void displayNode(node *p){
//     if(p == NULL){
//         printf("Empty data\n");
//         return;
//     }
//     elementtype temp;
//     printf("%-20s %-11s %-25s\n", "Name", "Phone", "Email");
//     temp = p->element;
//     printf("%-20s %-11s %-25s\n", temp.name, temp.phone, temp.email);
    
// }

void traversingList(node *r){
    if(r == NULL){
        printf("Empty data\n");
        return;
    }
    node *temp;
    int i = 0;
    printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)");
    for(temp = r; temp != NULL; temp = temp->next){
        i ++;
        printf("%-3d %-30s %-20s %-20s %-6.3f\n", i, temp->element.Model, temp->element.memo, temp->element.screen, temp->element.price);
    }
}

void insertAtHead(elementtype e){           //Current pointer move to root
    node *new = makeNewNode(e);
    new->next = root;
    root = new;
    cur = root;
    prev = NULL;
    // total ++;
}

void insertAfterCurrent(elementtype e){     //Current pointer move to the next node
    node *new = makeNewNode(e);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
        // total ++;
    }
    else if(cur == NULL)
        return;
    else{
        new->next = cur->next;
        cur->next = new;
        prev = cur;
        cur = new;
        // total ++;
    }

}

void insertBeforeCurrent(elementtype e){    //Current pointer move backward
    node *new = makeNewNode(e);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
    }
    else{
        prev->next = new;
        new->next = cur;
        cur = new;
    }
    // total ++;
}

node *insertAtPosition(node *root, elementtype ad, int n){
    node *temp;
    temp = root;
    int i = 1;
    if(n == 0){
        insertAtHead(ad);
        return root;
    }
    while(temp != NULL){
        if(i == n){
            node *new;
            new = makeNewNode(ad);
            new->next = temp->next;
            temp->next = new;
            return new;
        }
        temp = temp->next;
        i ++;
    }
    return cur;
}

node *deleteAtPosition(node *root, int n){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    node *pretemp;
    pretemp = (node*)malloc(sizeof(node));
    temp = root;
    int i = 1;
    while(temp != NULL){
        if(n == 0){
            temp = root;
            root = root->next;
            free(temp);
            return root;
        }
        if(i == n){
            pretemp->next = temp->next;
            free(temp);
            return root;
        }
        pretemp = temp;
        temp = temp->next;
        i ++;
    }
    return root;
}

void deleteFirstNode(){
    node *del;
    del = root;
    if (del == NULL)
        return;
    root = del->next;
    free(del);
}

void deleteCur(){                    //Current move to the next node
    if(cur == NULL)
        return;
    if(cur == root){
        deleteFirstNode();
        return;
    }
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
}

void freeAll(node *r){
    node *temp;
    temp = r;
    while(temp != NULL){
        free(temp);
        r = r->next;
        temp = r;
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

node *split(node* r, int n1, int n2){
    node *temp, *pretemp;
    temp = root;
    node *sublist;
    int i = 0;
    if(n1 == 0){
        sublist = root;
        for(int j = 1; j < n2; j ++){
            root = root->next;
        }
        temp = root;
        root = root->next;
        temp ->next = NULL;
        return sublist;
    }

    while(i != n1 && temp != NULL){
        pretemp = temp;
        temp = temp->next;
        i ++;
    }
    sublist = temp;

    for(int j = 1; j < n2; j ++){
        temp = temp->next;
    }
    pretemp->next = temp->next;
    temp->next = NULL;
    return sublist;
}

void printListToFile(node *r, char filepath[]){
    FILE *f;
    node *temp;
    temp = r;
    if ( (f = fopen(filepath, "w")) == NULL){
        printf("Cannot open %s\n", filepath);
        return;
    }
    fprintf(f, "%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)");
    int i = 0;
    while(temp != NULL){
        i++;
        fprintf(f, "%-3d %-30s %-20s %-20s %-6.3f\n", i, temp->element.Model, temp->element.memo, temp->element.screen, temp->element.price);
        temp = temp->next;
    }
    fclose(f);
}
