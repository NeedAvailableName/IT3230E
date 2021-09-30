/*Create a student list file of your class
Write a student management program that uses a binary search tree with nodes that are student names, 
knowing that the comparison between names based on the Vietnamese name matching principle is as follows:
Compare first name (in alphabetical order), then middle name, then the last name
The program has function of displaying the class list sorted in ascending order 
to the screen and searching students*/
typedef struct {
    char name[40];
}VNname;
typedef VNname KeyType;
#include"BST.h"
char *name(char str[]) {
    int i = strlen(str) - 1;
    while(i >= 0 && str[i] != '_') i--;
    return str + i + 1;
}
void InsertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        strcpy((*root)->key.name, x.name);
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(strcmp(name(x.name), name((*root)->key.name)) < 0) InsertNode(x, &(*root)->left);
    else if(strcmp(name(x.name), name((*root)->key.name)) > 0) InsertNode(x, &(*root)->right);
    else if(strcmp(name(x.name), name((*root)->key.name)) == 0) {
        if(strcmp(x.name, (*root)->key.name) < 0) InsertNode(x, &(*root)->left);
        else InsertNode(x, &(*root)->right);
    }
}
TreeType Search(char x[], TreeType root) {
    if(root == NULL) return NULL;
    else if(strcmp(root->key.name, x) == 0) return root;
    else if(strcmp(name(x), name(root->key.name)) < 0) return Search(x, root->left);
    else if(strcmp(name(x), name(root->key.name)) > 0) return Search(x, root->right);
    else if(strcmp(name(x), name(root->key.name)) == 0) {
        if(strcmp(x, root->key.name) < 0) return Search(x, root->left);
        else return Search(x, root->right);
    }
}
void InorderPrint(TreeType T) {
    if(T != NULL) {
        InorderPrint(T->left);
        printf("%s\n", T->key.name);
        InorderPrint(T->right);
    }
} 
int main() {
    TreeType root;
    root = NULL;
    int opt;
    do{
        printf("1. Import from file\n");
        printf("2. Display in ascending order\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr = fopen("studentlist.txt", "r");
                if(fptr == NULL) printf("cannot open file\n");
                KeyType *s = (KeyType *)malloc(sizeof(KeyType));
                while(!feof(fptr)) {
                    fscanf(fptr, "%s", s);
                    InsertNode(*s, &root);
                }
                fclose(fptr);
                free(s);
                printf("Successful\n");
            }
            break;
            case 2: {
                InorderPrint(root);
            }
            break;
            case 3: {
                char *s = (char *)malloc(40);
                printf("Enter the name to search: ");
                fflush(stdin);
                gets(s);
                if(Search(s, root)) printf("Searching result: In the list\n");
                else printf("No result\n");
                free(s);
            }
            break;
            case 4: {
                printf("Exit\n");
                freeTree(root);
            }
            break;
            default:
            break;
        }
    }while(opt != 4);
    return 0;
}