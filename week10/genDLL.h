#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// typedef struct{
//     char Model[40];
//     char memo[10];
//     char screen[5];
//     float price;
// }phoneDB_t;
// typedef phoneDB_t Eletype;
typedef struct {
    int memo;
    int ID;
}program_t;
typedef program_t Eletype;
struct node_t {
    Eletype element;
    struct node_t *next;
    struct node_t *prev;
};
typedef struct node_t node;
typedef node* doublelist;
// doublelist root = NULL;
// doublelist cur = NULL;
// doublelist tail = NULL;
// int total;

doublelist makeNewNode(Eletype e) {
    doublelist new = (doublelist)malloc(sizeof(node));
    new->element = e;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

Eletype enterProgram() {
    Eletype *pro = (Eletype *)malloc(sizeof(Eletype));
    printf("Enter memory size: ");
    scanf("%d", &pro->memo);
    printf("Program ID?: ");
    scanf("%d", &pro->ID);
    return *pro;
}

/*Eletype *phoneData(doublelist t){
    Eletype *temp;
    temp = (Eletype*)malloc(sizeof(Eletype));
    strcpy(temp->Model, t->element.Model);
    strcpy(temp->memo, t->element.memo);
    strcpy(temp->screen, t->element.screen);
    temp->price = t->element.price;
    return temp;
}

void traverseList(doublelist *root, doublelist *tail){
    doublelist temp = *root;
    int i = 0;
    printf("%-3s %-20s %-12s %-25s\n","No", "Name", "Phone", "Email");
    while(temp != NULL){
        i ++;
        printf("%-3d %-20s %-12s %-25s\n", i, temp->element.name, temp->element.tel, temp->element.email);
        temp = temp->next;
    }
}

void traversingList(doublelist *root, doublelist *tail){
    if(*root == NULL){
        printf("Empty data\n");
        return;
    }
    doublelist temp = *root;
    int i = 0;
    printf("\n%-3s %-10s %-10s\n", "ID", "Memory", "Queue");
    while(temp != NULL){
        printf("%-3d %-30s %-20s %-20s %-6.3f\n", i, temp->element.Model, temp->element.memo, temp->element.screen, temp->element.price);
        i ++;
        temp = temp->next;
    }
}

void traverseBackward(doublelist *root, doublelist *tail){
    doublelist temp = *tail;
    int i = 0;
    printf("\n%-3s %-30s %-20s %-20s %-10s\n", "No", "Model", "Memory space (GB)", "Screen size (inches)", "Price ($)");
    while(temp != NULL){
        printf("%-3d %-30s %-20s %-20s %-6.3f\n", i, temp->element.Model, temp->element.memo, temp->element.screen, temp->element.price);
        i++;
        temp = temp->prev;
    }
}*/

void insertAtHead(Eletype e, doublelist *root, doublelist *tail, doublelist *cur){
    doublelist new = makeNewNode(e);
    if( *root == NULL){
        *root = new;
        *tail = new;
        *cur = new;
        return;
    }
    new->next = *root;
    (*root)->prev = new;
    *root = new;
    *cur = *root;
}

void insertAtTail(Eletype e, doublelist *root, doublelist *tail, doublelist *cur){
    doublelist new = makeNewNode(e);
    if( *tail == NULL){
        *root = new;
        *tail = new;
        *cur = new;
        return;
    }
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    *cur = *tail;
}

void insertAfter(Eletype e, doublelist *root, doublelist *tail, doublelist *cur){
    doublelist new = makeNewNode(e);
    if(*root == NULL){
        new->element.ID = 1;
        *root = new;
        *tail = new;
        *cur = new;
        return;
    }
    if(*cur == NULL){
        printf("Current pointer is NULL\n");
        return;
    }
    if(*cur == *tail){
        insertAtTail(e, root, tail, cur);
        return;
    }
    new->element.ID = (*cur)->element.ID + 1;
    new->next = (*cur)->next;
    (*cur)->next = new;
    new->prev = *cur;
    *cur = new;
    new = new->next;
    new->prev = *cur;
}

void insertBefore(Eletype e, doublelist *root, doublelist *tail, doublelist *cur){
    doublelist new = makeNewNode(e);
    if(*root == NULL){
        *root = new;
        *tail = new;
        *cur = new;
        return;
    }
    if(*cur == NULL){
        printf("Current pointer is NULL\n");
        return;
    }
    if(*cur == *root){
        insertAtHead(e, root, tail, cur);
        return;
    }
    new->prev = (*cur)->prev;
    (*cur)->prev = new;
    new->next = *cur;
    *cur = new;
    new = new->prev;
    new->next = *cur;
    return;
}

void insertAtPosition(Eletype e, int position, doublelist *root, doublelist *tail, doublelist *cur){
    doublelist temp = *root;
    int i = 0;
    if(position < 0){
        insertAtHead(e, root, tail, cur);
    }
    while(temp != NULL && i < position){
        temp = temp->next;
        i ++;
    }
    *cur = temp;
    insertAfter(e, root, tail, cur);
}

void deleteFirstNode(doublelist *root, doublelist *tail, doublelist *cur){
    if(*root == NULL){
        printf("Empty list\n");
        return;
    }
    doublelist p = *root;
    if((*root)->next == NULL){
        free(p);
        *root = NULL;
        *tail = NULL;
        *cur = NULL;
        return;
    }
    *root = (*root)->next;
    *cur = *root;
    (*root)->prev = NULL;
    free(p);
}

void deleteAtTail(doublelist *root, doublelist *tail, doublelist *cur){
    if(*tail == NULL){
        printf("Empty list\n");
        return;
    }
    doublelist p = *tail;
    if((*tail)->prev == NULL){
        free(p);
        *root = NULL;
        *tail = NULL;
        *cur = NULL;
        return;
    }
    *tail = (*tail)->prev;
    *cur = *tail;
    (*tail)->next = NULL;
    free(p);
}

void deleteAtPosition(int position, doublelist *root, doublelist *tail, doublelist *cur){
    doublelist temp = *root;
    int i = 0;
    if(position < 0){
        deleteFirstNode(root, tail, cur);
    }
    while(temp != NULL && i < position){
        temp = temp->next;
        i ++;
    }
    if(temp == *tail){
        deleteAtTail(root, tail, cur);
        return;
    }
    *cur = temp->prev;
    temp->next->prev = *cur;
    (*cur)->next = temp->next;
    free(temp);
}

void deleteNode(doublelist p, doublelist *root, doublelist *tail, doublelist *cur){
    if(*root == NULL){
        printf("Empty list\n");
        return;
    }

    if (p == *root){
        *root = (*root)->next;
    }
    else{
        p->prev->next = p->next;
    }

    if(p->next != NULL){
        p->next->prev = p->prev;
    }
    else{                               //p == *tail
        *tail = (*tail)->prev;
    }
    *cur = p->prev;
    free(p);
}

void deleteCurrent(doublelist *root, doublelist *tail, doublelist *cur){
    if(*root == NULL){
        printf("Empty list\n");
        return;
    }

    if(*cur == *root){
        deleteFirstNode(root, tail, cur);
        return;
    }

    if(*cur == *tail){
        deleteAtTail(root, tail, cur);
        return;
    }

    doublelist temp = *cur;
    *cur = (*cur)->prev;
    (*cur)->next = temp->next;
    temp->next->prev = *cur;
    free(temp);
}

void deleteID(int id, doublelist *root, doublelist *tail, doublelist *cur){
    doublelist temp = *root;
    while(temp != NULL){
        if(temp->element.ID == id){
            *cur = temp;
            usedMem = usedMem - (*cur)->element.memo;
            deleteCurrent(root, tail, cur);
            printf("Kill successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Kill fail!\n");
}

void reverseList(doublelist *root, doublelist *tail, doublelist *cur){
    doublelist temp = NULL;
    *tail = *root;
    while(*root != NULL){
        *cur = *root;
        *root = (*root)->next;
        (*cur)->next = temp;
        // temp->prev = *cur;
        // if(temp->next == NULL)
        //     *tail = temp;
        temp = *cur;
        temp->prev = *root;
    }
    *root = temp;
}

void freeAll(doublelist *root, doublelist *tail, doublelist *cur){
    doublelist temp;
    temp = *root;
    while(temp != NULL){
        free(temp);
        *root = (*root)->next;
        temp = *root;
    }
    *tail = NULL;
    *cur = NULL;
}

