#include<stdio.h>
#include<stdlib.h>
typedef struct address_t{
    char name[20];
    char tel[11];
    char email[25];
} address;
struct list_el;
address addr;
struct list_el {
    address addr;
    struct list_el *next;
};
typedef struct list_el node_addr;
node_addr *root, *cur, *prev;

/*node_addr *make_new_node() {
    node_addr *newN = (node_addr *)malloc(sizeof(node_addr));
    newN->addr = addr;
    newN->next=NULL;
    return newN;
}*/

node_addr *makeNewNode(address addr) {
    node_addr *newN = (node_addr *)malloc(sizeof(node_addr));
    newN->addr = addr;
    newN->next = NULL;
    return newN;
}

address readNode() {
    address tmp;
    printf("Enter the name: ");
    gets(tmp.name);
    fflush(stdin);
    printf("Enter the tel: ");
    gets(tmp.tel);
    printf("Enter the email: ");
    gets(tmp.email);
    return tmp;
}

void displayNode(node_addr *p) {
    printf("%-30s\t%-20s\t%-20s\n", p->addr.name, p->addr.tel, p->addr.email);
}

void insertAtHead(address addr) {
    node_addr *newN = makeNewNode(addr);
    newN->next = root;
    root = newN;
    cur = root;
}

void insertAfterCurrent(address addr) {
    node_addr *newN = makeNewNode(addr);
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

void insertBeforeCurrent(address addr) {
    node_addr *newN = makeNewNode(addr);
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
    node_addr *del = root;
    if(del == NULL) return;
    root = del->next;
    free(del);
    cur = root;
}

void deleteCurrentElement() {
    if(cur == NULL) return;
    if(cur == root) deleteFirstElement();
    node_addr *p = root;
    prev = root;
    while(prev->next != cur) {
        prev = prev->next;
    }
    prev->next = cur->next;
    free(cur);
    cur = prev->next;
}

void traversingList() {
    node_addr *p;
    for (p = root; p != NULL; p = p->next) {
        displayNode(p);
    }
}

int main() {
    address tmp;
    tmp = readNode();
    root = makeNewNode(tmp);
    cur = root;
    node_addr *newN;
    int i;
    for(i = 0; i < 3; i++) {
        tmp = readNode();
        newN = makeNewNode(tmp);
        cur->next = newN;
        cur = newN;
    }
    //tmp = readNode(); 
    //insertAtHead(tmp);
    //insertAfterCurrent(tmp);
    //insertBeforeCurrent(tmp);
    //deleteFirstElement();
    deleteCurrentElement();
    traversingList();
    return 0;
}