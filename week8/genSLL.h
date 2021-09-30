#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*typedef struct {
    char model[40];
    char memory[10];
    char screen[10];
    long price;
} phone;*/

typedef student elementtype;
struct node_t {
    elementtype element;
    struct node_t *next;
};
typedef struct node_t node;
node *root, *cur, *prev, *tail;
elementtype *s;

node *makeNewNode(elementtype addr) {
    node *newN = (node *)malloc(sizeof(node));
    newN->element = addr;
    newN->next=NULL;
    return newN;
}

/*node_addr *makeNewNode(address addr) {
    node_addr *newN = (node_addr *)malloc(sizeof(node_addr));
    newN->addr = addr;
    newN->next = NULL;
    return newN;
}*/

elementtype readNode() {
    
}

/*void displayNode(node *p) {
    printf("%-30s %-20s %-20s %-10ld\n", p->element.model, p->element.memory, p->element.screen, p->element.price);
}*/

void insertAtHead(elementtype addr) {
    node *newN = makeNewNode(addr);
    newN->next = root;
    root = newN;
    cur = root;
}

void insertAfterCurrent(elementtype addr) {
    node *newN = makeNewNode(addr);
    if(root == NULL) {
        root = newN;
        cur = root;
    }
    else if(cur == NULL) {
        free(newN);
        return;
    }
    else {
        newN->next = cur->next;
        cur->next = newN;
        cur = cur->next;
    }
}

void insertBeforeCurrent(elementtype addr) {
    node *newN = makeNewNode(addr);
    if(cur == root) {
        insertAtHead(addr);
    }
    else if(root == NULL) {
        root = newN;
    }
    else {
        prev = root;
        while(prev->next != cur) {
            prev = prev->next;
        }
        prev->next = newN;
        newN->next = cur;
    }
}

void deleteFirstElement() {
    node *del = root;
    if(del == NULL) return;
    root = del->next;
    free(del);
    cur = root;
}

void deleteCurrentElement() {
    if(cur == NULL) return;
    if(cur == root) deleteFirstElement();
    prev = root;
    while(prev->next != cur) {
        prev = prev->next;
    }
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
}

void traversingList() {
    node *p;
    for (p = root; p != NULL; p = p->next) {
        displayNode(p);
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

void deleteAtPosition(int pos) {
    int i = 0;
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
    for(i = 0; i < pos; i++) {
        if(cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }
        else break;
    }
    if(i < pos || pos < 0) {
        printf("There is no node at position %d", pos);
        return;
    }
    deleteCurrentElement();
}

node *insertAtPosition(elementtype addr, int pos) {
    int i;
    cur = root;
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);
    if(pos <= 0) insertAtHead(addr);
    for(i = 1; i < pos; i++) {
        if(cur->next != NULL) cur = cur->next;
    }
    addr = rea();
    insertAfterCurrent(addr);
    return cur;
}

node *split(node *p, int n1, int n2) {
    int i;
    printf("Enter the start postion: ");
    scanf("%d", &n1);
    printf("Enter the number of record: ");
    scanf("%d", &n2);
    for(p = root; p != NULL; p = p->next) {
        i++;
        if(i >= n1 && i <= (n1 + n2)) {
            elementtype tmp;
            node *newN = makeNewNode(tmp);
            newN = p;
            displayNode(newN);
        }
        if(i > (n1 + n2)) {
            elementtype tmp;
            node *newN = makeNewNode(tmp);
            newN = p;
            displayNode(newN);
        }
    }
    return p;
}
void importFromFile() {
    FILE *fptr = fopen("PhoneDB.dat", "rb");
    for(cur = root; cur != NULL; cur = cur->next) {
        elementtype *s =(elementtype *)malloc(sizeof(elementtype));
        while(!feof(fptr)) {
            if(fread(s, sizeof(elementtype), 1, fptr) != 0) {
                cur->element = *s;
            }
        }
        free(s);
    }
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