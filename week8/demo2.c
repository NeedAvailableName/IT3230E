#include<stdlib.h>
#include<stdio.h>
typedef struct address_t{
    char name[20];
    char tel[11];
    char email[25];
} address;

typedef address elementtype;
struct node_t {
    elementtype element;
    struct node_t *next;
    struct node_t *prev;
};
typedef struct node_t node;
typedef node *doubleList;
doubleList root, cur, tail;

elementtype readNode() {
    elementtype ele;
    printf("Enter the name: ");
    gets(ele.name);
    fflush(stdin);
    printf("Enter the tel: ");
    gets(ele.tel);
    printf("Enter the email: ");
    gets(ele.email);
    return ele;
}

node *makeNewNode(elementtype addr) {
    node *new = (node *)malloc(sizeof(node));
    new->element = addr;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void displayNode(node *p) {
    printf("%-30s\t%-20s\t%-20s\n", p->element.name, p->element.tel, p->element.email);
}

void traversingList() {
    node *p;
    for (p = root; p != NULL; p = p->next) {
        displayNode(p);
    }
}

void insertAtHead(elementtype ele) {
    node *new = makeNewNode(ele);
    ele = readNode();
    if(root = NULL) {
        root = new;
        tail = new;
        cur = new;
        return;
    }
    new->next = root;
    root->prev = new;
    root = new;
    cur = root;
}

void insertAfterCurrent(elementtype ele) {
    node *new = makeNewNode(ele);
    ele = readNode();
    if(root == NULL) {
        root = new;
        cur = new;
        tail = new;
    }
    else if(cur == NULL) {
        printf("Current pointer is NULL\n");
        return;
    }
    else {
        new->next = cur->next;
        if(cur->next == NULL) {
            cur->next->prev = new;
        }
        else {
            tail = new;
        }
        cur->next = new;
        cur->prev = cur;
        cur = new;
    }
}

/*void makeNullList(doubleList *root, doubleList *cur, doubleList *tail) {
    *root = NULL;
    *cur = NULL;
    *tail = NULL;
}*/

int isEmpty(doubleList root) {
    return root == NULL;
}

/*void *insertAtHead(doubleList *root, doubleList *cur, doubleList *tail, elementtype addr) {
    node *new = makeNewNode(addr);
    if(*root == NULL) {
        *root = NULL;
        *cur = NULL;
        *tail = NULL;
        return;
    }
    new->next = *root;
    *root->prev = new;
    *root = new;
    *cur = *root;
}*/

void append(elementtype ele) {
    node *new = makeNewNode(ele);
    if(tail == NULL) {
        root = new;
        cur = new;
        tail = new;
        return;
    }
    tail->next = new;
    new->next = NULL;
    new->prev = tail;
    tail = new;
    cur = tail;
}

/*void deleteList(doubleList p, doubleList *root) {
    if(*root == NULL) printf("Empty list\n");
    else {
        if(p == *root) *root = *root->next;
        else p->prev->next = p->next;
        if(p->next != NULL) p->next->prev = p->prev;
        free(p);
    }
}*/

int main() {
    int i;
    elementtype tmp;
    for(i = 0; i < 3; i++) {
        readNode(tmp);    
        node *new = makeNewNode(tmp);
        //insertAtHead(tmp);
    }
    insertAtHead(tmp);
    insertAfterCurrent(tmp);
    traversingList();
    return 0;
}