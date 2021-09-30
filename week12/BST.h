#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
/*TreeType search(KeyType x, TreeType root) {
    if(root == NULL) return NULL;
    else if(root->key == x) return root;
    else if(root->key < x) return search(x, root->right);
    else return search(x, root->left);
}
void insertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(x < (*root)->key) insertNode(x, &(*root)->left);
    else if(x > (*root)->key) insertNode(x, &(*root)->right);
}*/
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
/*void deleteNode(KeyType x, TreeType *root) {
    if(*root != NULL) {
        if(x < (*root)->key) deleteNode(x, &(*root)->left);
        else if(x > (*root)->key) deleteNode(x, &(*root)->right);
        else if((*root)->left == NULL && (*root)->right == NULL) *root = NULL;
        else if((*root)->left == NULL) (*root) = (*root)->right;
        else if((*root)->right == NULL) (*root) = (*root)->left;
        else (*root)->key = deleteMin(&(*root)->right);
    }
}*/
void freeTree(TreeType T) {
    if(T != NULL) {
        freeTree(T->left);
        freeTree(T->right);
        freeTree(T);
    }
}