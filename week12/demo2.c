typedef int KeyType;
#include"BST.h"
int main(){
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;
    TreeType root;
    root = NULL;
    for(i = 0; i < 10; i++) {
        insertNode(a[i], &root);
    }
    //inorderPrint(root);
    //if(search(8, root)) printf("Seaching result: Done\n");
    //else printf("No result\n");
    deleteNode(7, &root);
    inorderPrint(root);
    return 0;
}