#include<stdlib.h>
#include<stdio.h>
#include"genSLL.h"

int main() {
    elementtype tmp;
    tmp = readNode();
    root = makeNewNode(tmp);
    cur = root;
    node *newN;
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
    //deleteCurrentElement();
    listReverse(prev);
    traversingList();
    return 0;
}