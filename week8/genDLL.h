#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct {
    char model[40];
    char memory[10];
    char screen[10];
    long price;
} phone;

typedef phone elementtype;
struct node_t {
    elementtype element;
    struct node_t *next;
    struct node_t *prev;
};
typedef struct node_t node;
typedef node *doubleList;
doubleList root, cur, tail;

node *makeNewNode(elementtype addr) {
    node *new = (node *)malloc(sizeof(node));
    new->element = addr;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

elementtype readNode() {
    elementtype ele;
    printf("Enter the model: ");
    fflush(stdin);
    gets(ele.model);
    fflush(stdin);
    printf("Enter the memory space: ");
    gets(ele.memory);
    printf("Enter the screen size: ");
    gets(ele.screen);
    printf("Enter the price: ");
    scanf("%ld", &ele.price);
    return ele;
}

void displayNode(node *p) {
    int i = 0;
    printf("%-5s %-30s %-20s %-20s %-10s\n", "Num", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    printf("%-5d %-30s %-20s %-20s %-10ld\n", i+1, p->element.model, p->element.memory, p->element.screen, p->element.price);
}

void traversingList() {
    node *p;
    int i = 0;
    printf("%-5s %-30s %-20s %-20s %-10s\n", "Num", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    for(p = root; p != NULL; p = p->next) {
        printf("%-5d %-30s %-20s %-20s %-10ld\n", i+1, p->element.model, p->element.memory, p->element.screen, p->element.price);
    }
}

void insertAtHead(elementtype ele) {
    node *new = makeNewNode(ele);
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

void insertBeforeCurrent(elementtype ele) {
    node *new = makeNewNode(ele);
    if(cur == root) {
        insertAtHead(ele);
    }
    else if(root == NULL) {
        root = new;
        cur = new;
        tail = new;
    }
    else {
        new->prev = cur->prev;
        cur->prev = new;
        new->next = cur;
        cur = new;
        new = new->prev;
        new->next = cur;
        return;
    }
}

void insertAfterCurrent(elementtype ele) {
    node *new = makeNewNode(ele);
    if(root == NULL) {
        root = new;
        tail = new;
        cur = new;
    }
    else if(cur == NULL) {
        printf("Current pointer is NULL\n");
        return;
    }
    else {
        /*new->next = cur->next;
        if(cur->next == NULL) {
            cur->next->prev = new;
        }
        else {
            tail = new;
        }
        cur->next = new;
        cur->prev = cur;
        cur = new;*/
        new->next = cur->next;
        cur->next = new;
        new->prev = cur;
        cur = new;
        new = new->next;
        new->prev = cur;
    }
}

void insertAtPosition(elementtype addr, int pos) {
    int i;
    cur = root;
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);
    if(pos <= 0) insertAtHead(addr);
    for(i = 1; i < pos; i++) {
        if(cur->next != NULL) cur = cur->next;
    }
    insertAfterCurrent(addr);
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

void deleteFirstElement() {
    node *del = root;
    if(del == NULL) return;
    root = del->next;
    free(del);
    cur = root;
}

void deleteAtLast() {
    if(root == NULL) printf("Empty list\n");
    else {
        cur = root;
        while(cur != NULL) {
            cur = cur->next;
        }
        cur->prev->next = NULL;
        free(cur);
    }
}

void deleteCurrentElement() {
    if(cur == NULL) return;
    if(cur == root) deleteFirstElement();
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
}

void deleteAtPosition(int pos) {
    int i = 0;
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
    for(i = 0; i < pos; i++) {
        if(cur->next != NULL) {
            cur = cur->next;
        }
        else break;
    }
    if(i < pos || pos < 0) {
        printf("There is no node at position %d", pos);
        return;
    }
    else {
        deleteCurrentElement();
        printf("Successful\n");
    }
}

node *listReverse(node *root) {
    node *cur, *prev;
    cur = prev = NULL;
    while(root != NULL) {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

void exportToFile() {
    int opt;
    printf("1. Export to file .dat\n");
    printf("2. Export to file .txt\n");
    scanf("%d", &opt);
    if(opt == 1) {
        FILE *fptr = fopen("PhoneDB.dat", "w+b");
        elementtype *s = (elementtype *)malloc(sizeof(elementtype));
        for(cur = root; cur != NULL; cur = cur->next) {
            s = &cur->element;
            fwrite(s, sizeof(elementtype), 1, fptr);
        }
        free(s);
        fclose(fptr);
    }
    if (opt == 2) {
        FILE *fptr = fopen("PhoneDB.txt", "w");
        elementtype *s = (elementtype *)malloc(sizeof(elementtype));
        for(cur = root; cur != NULL; cur = cur->next) {
            s = &cur->element;
            fwrite(s, sizeof(elementtype), 1, fptr);
        }
        free(s);
        fclose(fptr);
    }
}

void freeNode(node *to_free) {
    to_free = root;
    while(to_free != NULL) {
        root = root->next;
        free(to_free);
        to_free = root;
    }
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