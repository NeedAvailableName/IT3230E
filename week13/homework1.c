/*Write a English-Vietnamese dictionary in ICT program with basic functionalities
Hint:
- An item in the dictionary includes: english word - description in Vietnamese 
(you can add some example sentences or list of synnonyms but they are optional)
- BST should be used
Main features: searching, adding word item, delete word and save data to file*/
typedef struct {
    char eng[100];
    char vn[100];
}dict;
typedef dict KeyType;
#include"BST.h"
TreeType Search(char x[], TreeType root) {
    if(root == NULL) return NULL;
    else if(strcmp(root->key.eng, x) == 0) return root;
    else if(strcmp(root->key.eng, x) < 0) return Search(x, root->right);
    else return Search(x, root->left);
}
void InsertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(strcmp(x.eng, (*root)->key.eng) < 0) InsertNode(x, &(*root)->left);
    else if(strcmp(x.eng, (*root)->key.eng) > 0) InsertNode(x, &(*root)->right);
}
void DeleteNode(char x[], TreeType *root) {
    if(*root != NULL) {
        if(strcmp(x, (*root)->key.eng) < 0) DeleteNode(x, &(*root)->left);
        else if(strcmp(x, (*root)->key.eng) > 0) DeleteNode(x, &(*root)->right);
        else if((*root)->left == NULL && (*root)->right == NULL) *root = NULL;
        else if((*root)->left == NULL) (*root) = (*root)->right;
        else if((*root)->right == NULL) (*root) = (*root)->left;
        else (*root)->key = deleteMin(&(*root)->right);
    }
}
void displayNode(TreeType root) {
    printf("%s %s\n", root->key.eng, root->key.vn);
}
void InOrderPrint(TreeType root) {
    if(root != NULL) {
        InOrderPrint(root->left);
        printf("%s %s\n", root->key.eng, root->key.vn);
        InOrderPrint(root->right);
    }
}
void ExportToFile(TreeType T, FILE *fptr2) {
    if(T != NULL) {
        ExportToFile(T->left, fptr2);
        KeyType *s = (KeyType *)malloc(sizeof(KeyType));
        strcpy(s->eng, T->key.eng);
        strcpy(s->eng, T->key.vn);
        fprintf(fptr2, "%s %s\n", s->eng, s->vn);
        free(s);
        ExportToFile(T->right, fptr2);
    }
}

int main() {
    TreeType root;
    root = NULL;
    int opt;
    do {
        printf("\n");
        printf("1. Import from file\n");
        printf("2. Display to screen\n");
        printf("3. Search\n");
        printf("4. Add word item\n");
        printf("5. Delete word\n");
        printf("6. Save data to file\n");
        printf("7. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr = fopen("dictionary.txt", "r");
                if(fptr == NULL) {
                    printf("cannot open file\n");
                    return;
                }
                KeyType *s = (KeyType *)malloc(sizeof(KeyType));
                while(!feof(fptr)) {
                    fscanf(fptr, "%s %s", s->eng, s->vn);
                    InsertNode(*s, &root);
                }
                printf("Import from file successfully\n");
                free(s);
            }
            break;
            case 2: {
                InOrderPrint(root);
            }
            break;
            case 3:{
                char s[100];
                printf("Enter the word to search: ");
                fflush(stdin);
                gets(s);
                strcat(s, ":");
                if(Search(s, root)) {
                    printf("Searching result: ");
                    displayNode(Search(s, root));
                }
                else printf("No result\n");
            }
            break;
            case 4: {
                KeyType a;
                printf("Enter the English word: ");
                fflush(stdin);
                gets(a.eng);
                strcat(a.eng, ":");
                printf("Enter its meaning in Vietnamese: ");
                fflush(stdin);
                gets(a.vn);
                fflush(stdin);
                InsertNode(a, &root);
                printf("Add word successfully\n");
            }
            break;
            case 5: {
                char s[100];
                printf("Enter the word to delete: ");
                fflush(stdin);
                gets(s);
                strcat(s, ":");
                DeleteNode(s, &root);
                printf("Delete successfully\n");
            }
            break;
            case 6: {
                FILE *fptr = fopen("dictionary.txt", "w");
                if(fptr == NULL) {
                    printf("cannot open file\n");
                    return;
                }
                ExportToFile(root, fptr);
                printf("Export to file successfully\n");
            }
            break;
            case 7: {
                printf("Exit\n");
                freeTree(root);
            }
            default:
            break;
        }
    }while(opt != 7);
}