/*#include<stdio.h>
#include<stdlib.h>
typedef char elementType;
typedef struct node_t{
    elementType ele;
    struct node_t *left;
    struct node_t *right;
}node;
typedef node *tree;

void makeNullTree(tree *T) {
    (*T) = NULL;
}
int isEmpty(tree T) {
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
tree createNode(elementType e) {
    tree new;
    new = (tree)malloc(sizeof(tree));
    if(new != NULL) {
        new->left = NULL;
        new->right = NULL;
        new->ele = e;
    }
    return new;
}
int isLeaf(tree n) {
    if(n != NULL) {
        return((leftChild(n) == NULL) && (rightChild(n) == NULL));
    }
    else return -1;
}
int numNode(tree *T) {
    if(isEmpty(&T)) return 0;
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
void inorderPrint(tree T) {
    if(T != NULL) {
        inorderPrint(T->left);
        printf("%d\n", T->ele);
        inorderPrint(T->right);
    }
}
void postorderPrint(tree T) {
    if(T != NULL) {
        postorderPrint(T->left);
        postorderPrint(T->right);
        printf("%d\n", T->ele);
    }
}
void preorderPrint(tree T) {
    if(T != NULL) {
        printf("%d\n", T->ele);
        preorderPrint(T->left);
        preorderPrint(T->right);
    }
}*/
#include<stdio.h>
#include<stdlib.h>

typedef int elmType;
typedef struct node_type{
    elmType element;
    struct node_type *left;
    struct node_type *right;
}nodeType;
typedef nodeType* treeType;

void makeNullTree(treeType *t){
    (*t) = NULL;
}

elmType enterData(){
    printf("Enter number: ");
    elmType e;
    scanf("%d", &e);
    return e;
}

int emptyTree(treeType t){
    return (t == NULL);
}

treeType leftChild(treeType n){
    if(n != NULL)
        return n->left;
    return NULL;
}

treeType rightChild(treeType n){
    if(n != NULL)
        return n->right;
    return NULL;
}

treeType makeNode(elmType data){
    treeType n = (treeType)malloc(sizeof(nodeType));
    if(n != NULL){
        n->left = NULL;
        n->right = NULL;
        n->element = data;
    }
    return n;
}

int isLeaf(treeType n){
    if(n != NULL){
        return(leftChild(n) == NULL && rightChild(n) == NULL);
    }
    return -1;
}

treeType creatFrom2(elmType e, treeType l, treeType r){
    treeType n = (treeType)malloc(sizeof(nodeType));
    n->element = e;
    n->left = l;
    n->right = r;
    return n;
}

treeType addLeft(treeType *t, elmType data){
    nodeType *newNode = makeNode(data);
    if(*t == NULL){
        *t = newNode;
        return *t;
    }

    while((*t)->left != NULL){
        *t = (*t)->left;
    }
    (*t)->left = newNode;
    return newNode;
}

treeType addRight(treeType *t, elmType data){
    nodeType *newNode = makeNode(data);
    if(*t == NULL){
        *t = newNode;
        return *t;
    }
    treeType temp = *t;
    while(temp->right != NULL){
        temp = temp->right;
    }
    temp->right = newNode;
    return newNode;
}

// int max(int a, int b){
//     if(a >= b)
//         return a;
//     return b;
// }

int height(treeType t){
    int h = 0;
    if(t != NULL){
        h ++;
    }
    else{
        return h;
    }
    h += __max(height(leftChild(t)), height(rightChild(t)));
    return h;
}

int countLeaf(treeType t){
    int count = 0;
    if(t == NULL)
        return count;

    if(isLeaf(t)){
        count ++;
    }
    
    count += countLeaf(leftChild(t));
    count += countLeaf(rightChild(t));
    // treeType temp = t;
    // while(!isLeaf(rightChild(temp))){
    //     if(leftChild(temp) != NULL){
    //         count += countLeaf(leftChild(temp));
    //     }
    //     temp = rightChild(temp);
    // }
    // count ++;
    return count;
}

int countInternalNode(treeType t){
    int count= 0;
    if(t == NULL){
        return count;
    }

    if(!isLeaf(t)){
        count ++;
    }

    count += countInternalNode(leftChild(t));
    count += countInternalNode(rightChild(t));
    return count;
}

int countRightChild(treeType t){
    int count = 0;
    if(t == NULL){
        return count;
    }

    if(rightChild(t) != NULL){
        count ++;
    }

    count += countRightChild(leftChild(t));
    count += countRightChild(rightChild(t));
    return count;
}

void printTree(treeType t){
    if(t == NULL)
        return;
    printf("%d ", t->element);
    printTree(leftChild(t));
    printTree(rightChild(t));
}
void inorderPrint(treeType T) {
    if(T != NULL) {
        inorderPrint(T->left);
        printf("%d\n", T->element);
        inorderPrint(T->right);
    }
}
void postorderPrint(treeType T) {
    if(T != NULL) {
        postorderPrint(T->left);
        postorderPrint(T->right);
        printf("%d\n", T->element);
    }
}
void preorderPrint(treeType T) {
    if(T != NULL) {
        printf("%d\n", T->element);
        preorderPrint(T->left);
        preorderPrint(T->right);
    }
}

/*int main(){
    treeType t;
    t = makeNode(enterData());
    treeType temp;
    temp = addLeft(&t, enterData());
    addRight(&temp, enterData());
    temp = addLeft(&temp, enterData());
    addLeft(&temp, enterData());
    temp = addRight(&temp, enterData());
    addLeft(&temp, enterData());
    addRight(&temp, enterData());
    temp = addRight(&t, enterData());
    // printf("%d\n", t->element);
    addRight(&temp, enterData());
    temp = addLeft(&temp, enterData());
    addLeft(&temp, enterData());
    addRight(&temp, enterData());
    printTree(t);
    printf("\nHeight: %d\n", height(t));
    printf("Number of leaf: %d\n", countLeaf(t));
    printf("Number of internal nodes: %d\n", countInternalNode(t));
    printf("Number of right children: %d\n", countRightChild(t));
}*/