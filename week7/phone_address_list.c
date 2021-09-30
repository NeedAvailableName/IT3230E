#include<stdlib.h>
#include<stdio.h>
#include"phone_address_list.h"

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