#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//typedef int KeyType;
typedef struct Node {
    KeyType key;
    struct Node *left;
    struct Node *right;
}NodeType;
typedef NodeType *TreeType;

void makeNullTree(TreeType *T) {
    (*T) = NULL;
}

int isEmpty(TreeType *T) {
    return *T == NULL;
}

TreeType leftChild(TreeType n) {
    if(n != NULL) return n->left;
    else return NULL;
}

TreeType rightChild(TreeType n) {
    if(n != NULL) return n->right;
    else return NULL;
}

NodeType *createNode(KeyType e) {
    NodeType *new;
    new = (NodeType *)malloc(sizeof(NodeType));
    if(new != NULL) {
        new->left = NULL;
        new->right = NULL;
        new->key = e;
    }
    return new;
}

int isLeaf(TreeType n) {
    if(n != NULL) {
        return((leftChild(n) == NULL) && (rightChild(n) == NULL));
    }
    else return -1;
}

int numNode(TreeType *T) {
    if(isEmpty(&T)) return 0;
    else return 1 + numNode(leftChild(T)) + numNode(rightChild(T));
}

//search for number
TreeType search(int x, TreeType root) {
    if(root == NULL) return NULL;
    else if(root->key == x) return root;
    else if(root->key < x) return search(x, root->right);
    else return search(x, root->left);
}
//search for char
TreeType search(char x[], TreeType root) {
    if(root == NULL) return NULL;
    else if(strcmp(root->key, x) == 0) return root;
    else if(strcmp(root->key, x) < 0) return search(x, root->right);
    else return search(x, root->left);
}
//insert for number
void insertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(x < (*root)->key) insertNode(x, &(*root)->left);
    else if(x > (*root)->key) insertNode(x, &(*root)->right);
}
//insert for char
void insertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(strcmp(x, (*root)->key) < 0) insertNode(x, &(*root)->left);
    else if(strcmp(x, (*root)->key) > 0) insertNode(x, &(*root)->right);
}
void inorderPrint(TreeType T) {
    if(T != NULL) {
        inorderPrint(T->left);
        printf("%d\n", T->key);
        inorderPrint(T->right);
    }
}
void postorderPrint(TreeType T) {
    if(T != NULL) {
        postorderPrint(T->left);
        postorderPrint(T->right);
        printf("%d\n", T->key);
    }
}
void preorderPrint(TreeType T) {
    if(T != NULL) {
        printf("%d\n", T->key);
        preorderPrint(T->left);
        preorderPrint(T->right);
    }
}
KeyType deleteMin(TreeType *root) {
    KeyType k;
    if((*root)->left == NULL) {
        k = (*root)->key;
        (*root) = (*root)->right;
        return k;
    }
    else return deleteMin(&(*root)->left);
}
//delete for number
void deleteNode(int x, TreeType *root) {
    if(*root != NULL) {
        if(x < (*root)->key) deleteNode(x, &(*root)->left);
        else if(x > (*root)->key) deleteNode(x, &(*root)->right);
        else if((*root)->left == NULL && (*root)->right == NULL) *root = NULL;
        else if((*root)->left == NULL) (*root) = (*root)->right;
        else if((*root)->right == NULL) (*root) = (*root)->left;
        else (*root)->key = deleteMin(&(*root)->right);
    }
}
//delete for char
void deleteNode(char x[], TreeType *root) {
    if(*root != NULL) {
        if(strcmp(x, (*root)->key) < 0) deleteNode(x, &(*root)->left);
        else if(strcmp(x, (*root)->key) > 0) deleteNode(x, &(*root)->right);
        else if((*root)->left == NULL && (*root)->right == NULL) *root = NULL;
        else if((*root)->left == NULL) (*root) = (*root)->right;
        else if((*root)->right == NULL) (*root) = (*root)->left;
        else (*root)->key = deleteMin(&(*root)->right);
    }
}

//lower for number
void lowerThanKey(int x, TreeType root) {
    if(root != NULL) {
        if(root->key < x) {
            printf("%d", root->key);
        }
        lowerThanKey(x, root->left);
        lowerThanKey(x, root->right);
    }
}
//lower for char
void lowerThanKey(char x[], TreeType root) {
    if(root != NULL) {
        if(strcmp(root->key, x) < 0) {
            printf("%d", root->key);
        }
        lowerThanKey(x, root->left);
        lowerThanKey(x, root->right);
    }
}

//higher for number
void higherThanKey(int x, TreeType root) {
    if(root != NULL) {
        if(root->key > x) {
            printf("%d", root->key);
        }
        higherThanKey(x, root->left);
        higherThanKey(x, root->right);
    }
}
//higher for char
void higherThanKey(char x[], TreeType root) {
    if(root != NULL) {
        if(strcmp(root->key, x) > 0) {
            printf("%d", root->key);
        }
        higherThanKey(x, root->left);
        higherThanKey(x, root->right);
    }
}

void freeTree(TreeType T) {
    if(T != NULL) {
        freeTree(T->left);
        freeTree(T->right);
        freeTree(T);
    }
}