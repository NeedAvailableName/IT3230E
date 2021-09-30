#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*typedef struct{
    char Model[40];
    char memo[10];
    char screen[5];
    float price;
}phoneDB_t;
typedef phoneDB_t elementtype;*/
struct node_t {
    elementType element;
    struct node_t *next;
};
typedef struct node_t node;
typedef node *singlelist;

singlelist makeNewNode(elementType e){
    singlelist new = (singlelist)malloc(sizeof(singlelist));
    new->element = e;
    new->next = NULL;
    return new;
}

/*elementtype enterPhone(){
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
}*/

void insertAtHead(elementType e, singlelist *root, singlelist *cur, singlelist *prev) {           //Current pointer move to root
    singlelist new = makeNewNode(e);
    new->next = *root;
    *root = new;
    *cur = *root;
    *prev = NULL;
    // total ++;
}

void insertAtTail(elementType e, singlelist *root, singlelist *cur, singlelist *prev) {
    singlelist new = makeNewNode(e);
    *cur = *root;
    while(*cur != NULL) {
        *cur = (*cur)->next;
    }
    new = (*cur)->next;
    *cur = new;
}

void insertAfterCurrent(elementType e, singlelist *root, singlelist *cur, singlelist *prev) {     //Current pointer move to the next node
    singlelist new = makeNewNode(e);
    if(*root == NULL) {
        *root = new;
        *cur = *root;
        *prev = NULL;
        // total ++;
    }
    else if(*cur == NULL)
        return;
    else {
        new->next = (*cur)->next;
        (*cur)->next = new;
        *prev = *cur;
        *cur = new;
        // total ++;
    }

}

void insertBeforeCurrent(elementType e, singlelist *root, singlelist *cur, singlelist *prev) {    //Current pointer move backward
    singlelist new = makeNewNode(e);
    if (*root == NULL) {
        insertAtHead(e, root, cur, prev);
    }
    else if(*cur == *root) {
        insertAtHead(e, root, cur, prev);
    }
    else {
        (*prev)->next = new;
        new->next = *cur;
        *cur = new;
    }
    // total ++;
}

void insertAtPosition(elementType e, int position, singlelist *root, singlelist *cur, singlelist *prev) {
    int i = 2;
    if(position < 0) {
        insertAtHead(e, root, cur, prev);
    }
    else {
        for(*cur = *root; *cur != NULL; *cur = (*cur)->next) {
            if(i == position) break;
            else i++;
        }
        insertAfterCurrent(e, root, cur, prev);
    }
}

void deleteFirstNode(singlelist *root, singlelist *cur, singlelist *prev) {
    if(*root == NULL) {
        printf("Empty list\n");
        return;
    }
    singlelist del;
    del = *root;
    *root = del->next;
    *cur = *root;
    free(del);
}

void deleteCurrentNode(singlelist *root, singlelist *cur, singlelist *prev) {                    //Current move to the next node
    if(*cur == NULL)
        return;
    else if(*cur == *root){
        deleteFirstNode(root, cur, prev);
        return;
    }
    (*prev)->next = (*cur)->next;
    free(*cur);
    (*cur) = (*prev)->next;
}

void deleteAtPosition(int position, singlelist *root, singlelist *cur, singlelist *prev) {
    singlelist temp = (singlelist)malloc(sizeof(singlelist));
    singlelist pretemp = (singlelist)malloc(sizeof(singlelist));
    temp = *root;
    int i = 0;
    while(temp != NULL) {
        if(position <= 0) {
            deleteFirstNode(root, cur, prev);
        }
        pretemp = temp;
        temp = temp->next;
        i++;
        if(i == position-1) {
            pretemp->next = temp->next;
            *cur = pretemp->next; 
            free(temp);
            break;
        }
    }
}

void freeList(singlelist *root, singlelist *cur, singlelist *prev) {
    *cur = *root;
    while(*cur != NULL) {
        deleteCurrentNode(root, cur, prev);
    }
}

void reverseList(singlelist *root, singlelist *cur, singlelist *prev) {
    *cur = NULL;
    *prev = NULL;
    while(*root != NULL) {
        *cur = *root;
        *root = (*root)->next;
        (*cur)->next = *prev;
        *prev = *cur;
    }
    *root = *prev;
}

singlelist *splitList(int n1, int n2, singlelist *root, singlelist *cur, singlelist *prev) {
    singlelist temp, pretemp;
    temp = *root;
    singlelist *sublist;
    int i = 0;
    if(n1 == 0) {
        sublist = root;
        for(int j = 1; j < n2; j++){
            *root = (*root)->next;
        }
        temp = *root;
        *root = (*root)->next;
        temp->next = NULL;
        return sublist;
    }
    while(i != n1 && temp != NULL){
        pretemp = temp;
        temp = temp->next;
        i++;
    }
    *sublist = temp;
    for(int j = 1; j < n2; j++){
        temp = temp->next;
    }
    pretemp->next = temp->next;
    temp->next = NULL;
    return sublist;
}

void importFromFile(singlelist *root, singlelist *cur, singlelist *prev, char filepath[]) {
    FILE *fptr = fopen(filepath, "r");
    if(fptr == NULL) {
        printf("cannot open file\n");
        return;
    }
    while(!feof(fptr)) {
        elementType *s = (elementType *)malloc(sizeof(elementType));
        free(s);
    }
    fclose(fptr);
}

void exportToFile(singlelist *root, singlelist *cur, singlelist *prev, char filepath[]) {
    FILE *fptr;
    *cur = *root;
    if ((fptr = fopen(filepath, "w")) == NULL){
        printf("Cannot open %s\n", filepath);
        return;
    }
    //fprintf(fptr, "%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)");
    int i = 0;
    while(*cur != NULL){
        i++;
        //fprintf(fptr, "%-3d %-30s %-20s %-20s %-6.3f\n", i, (*cur)->element.Model, (*cur)->element.memo, (*cur)->element.screen, (*cur)->element.price);
        *cur = (*cur)->next;
    }
    fclose(fptr);
}
