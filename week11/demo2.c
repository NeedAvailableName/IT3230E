#include<stdio.h>
#include<stdlib.h>
typedef int elementType;
typedef struct node {
    elementType ele;
    struct node *left, *right;
}node;
typedef struct node *tree;

void makeNullTree(tree *T) {
    (*T) = NULL;
}
int isEmpty(tree *T) {
    return T == NULL;
}
tree leftChild(tree n) {
    if(n != NULL) return n->left;
    else return NULL;
}
tree rightChild(tree n) {
    if(n != NULL) return n->right;
    else return NULL;
}
tree *createNode(elementType e) {
    node *new;
    new = (node *)malloc(sizeof(node));
    if(new != NULL) {
        new->left = NULL;
        new->right = NULL;
        new->ele = e;
    }
    return new;
}
int isLeaf(tree n) {
    if(n != NULL) {
        return(leftChild(n) == NULL) && (rightChild(n) == NULL);
    }
    else return -1;
}
int numNode(tree T) {
    if(isEmpty(T)) return 0;
    else return 1 + numNode(leftChild(T)) + numNode(rightChild(T));
}
tree createFrom2(elementType v, tree l, tree r) {
    tree N;
    N = (node *)malloc(sizeof(node));
    N->ele = v;
    N->left = l;
    N->right = r;
    return N;
}
tree addLeft(tree *T, elementType e) {
    node *new = createNode(e);
    if(new == NULL) return new;
    if(*T == NULL) *T = new;
    else {
        node *Lnode = *T;
        while(Lnode->left != NULL) Lnode = Lnode->left;
        Lnode->left = new;
    }
    return new;
}
tree addRight(tree *T, elementType e) {
    node *new = createNode(e);
    if(new == NULL) return new;
    if(*T == NULL) *T = new;
    else {
        node *Rnode = *T;
        while(Rnode->right != NULL) {
            Rnode = Rnode->right;
            Rnode->right = new;
        } 
    }
    return new;
}
