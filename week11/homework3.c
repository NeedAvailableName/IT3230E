/*Add the following helper functions to general binary tree data structure:
- return the height of a binary tree
- return the number of leafs
- return the number of internal nodes
- count the number of right children
Use the library to create a binary tree and demonstrate the above functions*/
#include"Tree.h"

int func1(node *root) {
    if(root == NULL) return 0;
    else {
        int lHeight = func1(root->left);
        int rHeight = func1(root->right);
        if(lHeight > rHeight) return (lHeight + 1);
        else return(rHeight + 1);
    }
}
int func2(node *root) {
    int count;
    if(root == NULL) return 0;
    else if((root->left == NULL) && (root->right == NULL)) return 1;
    else return func2(root->left) + func2(root->right);
}
int func3(tree *T) {
    return(numNode(&T) - func2(&T));
}
int func4(tree *T) {
    int count = 0;
    while(rightChild(&T) != NULL) count++;
    return count;
}
int main() {
    tree *T;
    makeNullTree(T);
    tree root;
    int opt;
    elementType e;
    root = createNode(e);
    int i;
    for(i = 0; i < 5; i++) {
        addRight(&T, i);
    }
    do {
        printf("\n");
        printf("1. return the height of a binary tree\n");
        printf("2. return the number of leafs\n");
        printf("3. return the number of internal nodes\n");
        printf("4. count the number of right children\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                printf("The height is: %d\n", func1(root));
            }
            break;
            case 2: {
                printf("The number of leafs: %d\n", func2(root));
            }
            break;
            case 3: {
                printf("The number of internal nodes: %d\n", func3(&T));
            }
            break;
            case 4: {
                printf("The number of right children: %d\n", func4(&T));
            }
            break;
            case 5: {
                printf("Exit\n");
                free(T);
            }
            break;
            default:
            break;
        }
    }while(opt != 5);
    return 0;
}