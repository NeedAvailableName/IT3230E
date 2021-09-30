#include<stdio.h>
#include<stdlib.h>

typedef int elmType;
typedef struct node_type{
    elmType ele;
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
        n->ele = data;
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
    n->ele = e;
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
    printf("%d ", t->ele);
    printTree(leftChild(t));
    printTree(rightChild(t));
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