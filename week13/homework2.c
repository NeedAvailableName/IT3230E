/*Write 2 function in BST library:
- int lowerThanKey(key X, Tree root)
- int higherThanKey(key X, Tree root)
Each does the following tasks:
- list all node (info data) of which key is smaller (bigger) than X
- return the number of these nodes
Use these functions in Student management program. 
Program should allow to see students whose grade is higher a value inputted by user*/
typedef struct {
    char name[40];
    float grade;
}student;
typedef student KeyType;
#include"BST.h"
char *name(char str[]) {
    int i = strlen(str) - 1;
    while(i >= 0 && str[i] != '_') i--;
    return str + i + 1;
}
void InsertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        (*root)->key = x;
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
void HigherThanKey(float x, TreeType root) {
    if(root != NULL) {
        if(x < root->key.grade) {
            printf("%-25s %.2f\n", root->key.name, root->key.grade);
            HigherThanKey(x, root->left);
            HigherThanKey(x, root->right);
        }
    }
}
void InorderPrint(TreeType T) {
    if(T != NULL) {
        InorderPrint(T->left);
        printf("%-25s %.2f\n", T->key.name, T->key.grade);
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
        printf("4. Find student with higher grade\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr = fopen("studentlist.txt", "r");
                if(fptr == NULL) printf("cannot open file\n");
                KeyType *s = (KeyType *)malloc(sizeof(KeyType));
                while(!feof(fptr)) {
                    fscanf(fptr, "%s %f", s->name, &s->grade);
                    InsertNode(*s, &root);
                }
                fclose(fptr);
                free(s);
                printf("Import from file successfully\n");
            }
            break;
            case 2: {
                printf("%-25s %s\n", "Student name", "Grade");
                InorderPrint(root);
            }
            break;
            case 3: {
                char *s = (char *)malloc(40);
                printf("Enter the name to search: ");
                fflush(stdin);
                gets(s);
                if(Search(s, root)) printf("Searching result: %-25s %.2f\n", Search(s, root)->key.name, Search(s, root)->key.grade);
                else printf("No result\n");
                free(s);
            }
            break;
            case 4: {
                float grade;
                printf("Enter the grade: ");
                scanf("%f", &grade);
                printf("Student list with higher grade\n");
                HigherThanKey(grade, root);
            }
            break;
            case 5: {
                printf("Exit\n");
                freeTree(root);
            }
            default:
            break;
        }
    }while(opt != 5);
    return 0;
}