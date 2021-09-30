typedef struct {
    char name[10];
    int score;
}KeyType;
typedef struct {
    char name1[10];
    char name2[10];
    int score1;
    int score2;
}elementType;

typedef struct Node {
    KeyType key;
    struct Node *left;
    struct Node *right;
}NodeType;
typedef NodeType *TreeType;
//#include"BST.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SLL.h"

TreeType search(char x[], TreeType root) {
    if(root == NULL) return NULL;
    else if(strcmp(root->key.name, x) == 0) return root;
    else if(strcmp(root->key.name, x) < 0) return search(x, root->right);
    else return search(x, root->left);
}
void insertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(strcmp(x.name, (*root)->key.name) < 0) insertNode(x, &(*root)->left);
    else if(strcmp(x.name, (*root)->key.name) > 0) insertNode(x, &(*root)->right);
}
void InorderPrint(TreeType T) {
    if(T != NULL) {
        InorderPrint(T->left);
        printf("%-10s %d\n", T->key.name, T->key.score);
        InorderPrint(T->right);
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
void deleteNode(int x, TreeType *root) {
    if(*root != NULL) {
        if(x < (*root)->key.score) deleteNode(x, &(*root)->left);
        else if(x > (*root)->key.score) deleteNode(x, &(*root)->right);
        else if((*root)->left == NULL && (*root)->right == NULL) *root = NULL;
        else if((*root)->left == NULL) (*root) = (*root)->right;
        else if((*root)->right == NULL) (*root) = (*root)->left;
        else (*root)->key = deleteMin(&(*root)->right);
    }
}
void lowerThanKey(int x, TreeType root) {
    if(root != NULL) {
        if(root->key.score < x) {
            printf("%-10s\n", root->key.name);
        }
        lowerThanKey(x, root->left);
        lowerThanKey(x, root->right);
    }
}
void func5(TreeType root, FILE *fptr2) {
    if(root != NULL) {
        fprintf(fptr2, "%s\t%d\n", root->key.name, root->key.score);
        func5(root->left, fptr2);
        func5(root->right, fptr2);
    }
}
int main() {
    int opt;
    TreeType T;
    T = NULL;
    singlelist root = NULL, cur = NULL, prev = NULL;
    do {
        printf("1. Tao cay\n");
        printf("2. Ket qua\n");
        printf("3. Tim kiem\n");
        printf("4. Xuong hang\n");
        printf("5. Xuat file\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr1 = fopen("BongDa.txt", "r");
                if(fptr1 == NULL) printf("cannot open file\n");
                while(!feof(fptr1)) {
                    elementType *s = (elementType *)malloc(sizeof(elementType));
                    fscanf(fptr1, "%s\t%s\t%d\t%d", s->name1, s->name2, &s->score1, &s->score2);
                    insertAfterCurrent(*s, &root, &cur, &prev);
                }
                for(cur = root; cur != NULL; cur = cur->next) {
                    KeyType *a1 = (KeyType *)calloc(1, sizeof(KeyType));
                    KeyType *a2 = (KeyType *)calloc(1, sizeof(KeyType));
                    strcpy(a1->name, cur->element.name1);
                    strcpy(a2->name, cur->element.name2);
                    if(cur->element.score1 > cur->element.score2) {
                        a1->score += 3;
                        a2->score += 0; 
                    }
                    else if(cur->element.score1 == cur->element.score2) {
                        a1->score += 1;
                        a2->score += 1;
                    }
                    else {
                        a1->score += 0;
                        a2->score += 3;
                    }
                    if(search(a1->name, T)) search(a1->name, T)->key.score += a1->score;
                    else insertNode(*a1, &T);
                    if(search(a2->name, T)) search(a2->name, T)->key.score += a2->score;
                    else insertNode(*a2, &T);
                }
                fclose(fptr1);
            }
            break;
            case 2: InorderPrint(T);
            break;
            case 3: {
                char s[10];
                printf("Nhap ma doi: ");
                fflush(stdin);
                gets(s);
                if(search(s, T)) printf("%-10s %d\n", T->key.name, T->key.score);
                else printf("Khong co doi bong nay\n");
            }
            break;
            case 4: {
                int X;
                printf("Nhap so diem X: ");
                scanf("%d", &X);
                lowerThanKey(X, T);
                //deleteNode()
            }
            break;
            case 5: {
                FILE *fptr2 = fopen("KetQua.txt", "w");
                if(fptr2 == NULL) printf("cannot open file\n");
                func5(T, fptr2);
                fclose(fptr2);
            }
            break;
            case 6: printf("Exit\n");
            break;
        }
    }while(opt != 6);
    return 0;
}