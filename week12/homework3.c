/*Rewrite PhoneDB management program using BST. The searching key in a node is the phone model.
Required features: Import data from text file, Import data from dat file, Add phone model, Delete, 
Update, Searching, Displaying and Save data to file PhoneDB.dat*/
typedef struct {
    char model[40];
    char memo[10];
    char screen[5];
    int price;
}phone;
typedef phone KeyType;
#include"BST.h"

KeyType enterPhone(){
    KeyType *phoneDB;
    phoneDB = (KeyType *)malloc(sizeof(KeyType));
    printf("Enter model: ");
    scanf("%s", phoneDB->model);
    printf("Enter memory: ");
    scanf("%s", phoneDB->memo);
    printf("Enter screen size: ");
    scanf("%s", phoneDB->screen);
    printf("Enter price: ");
    scanf("%d", &phoneDB->price);
    return *phoneDB;
}
void displayNode(TreeType cur) {
    if(cur == NULL) {
        printf("Empty data\n");
        return;
    }
    printf("\n%-30s %-20s %-20s %-10s\n", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    printf("%-30s %-20s %-20s %-10d\n", cur->key.model, cur->key.memo, cur->key.screen, cur->key.price);
}
void InsertNode(KeyType x, TreeType *root) {
    if(*root == NULL) {
        *root = (NodeType *)malloc(sizeof(NodeType));
        (*root)->key = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if(strcmp(x.model, (*root)->key.model) < 0) InsertNode(x, &(*root)->left);
    else if(strcmp(x.model, (*root)->key.model) > 0) InsertNode(x, &(*root)->right);
}
TreeType Search(char s[], TreeType root) {
    if(root == NULL) return NULL;
    else if(strcmp(root->key.model, s) == 0) return root;
    else if(strcmp(root->key.model, s) < 0) return Search(s, root->right);
    else return Search(s, root->left);
}
void DeleteNode(char s[], TreeType *root) {
    if(*root != NULL) {
        if(strcmp(s, (*root)->key.model) < 0 ) DeleteNode(s, &(*root)->left);
        else if(strcmp(s, (*root)->key.model) > 0) DeleteNode(s, &(*root)->right);
        else if((*root)->left == NULL && (*root)->right == NULL) *root = NULL;
        else if((*root)->left == NULL) (*root) = (*root)->right;
        else if((*root)->right == NULL) (*root) = (*root)->left;
        else (*root)->key = deleteMin(&(*root)->right);
    }
}
void InorderPrint(TreeType T) {
    if(T != NULL) {
        InorderPrint(T->left);
        printf("%-30s %-20s %-20s %-10d\n", T->key.model, T->key.memo, T->key.screen, T->key.price);
        InorderPrint(T->right);
    }
}
void ExportToFile(TreeType T, FILE *fptr2) {
    if(T != NULL) {
        ExportToFile(T->left, fptr2);
        KeyType *s = (KeyType *)malloc(sizeof(KeyType));
        strcpy(s->model, T->key.model);
        strcpy(s->memo, T->key.memo);
        strcpy(s->screen, T->key.screen);
        s->price = T->key.price;
        fwrite(s, sizeof(KeyType), 1, fptr2);
        free(s);
        ExportToFile(T->right, fptr2);
    }
}
int main() {
    TreeType root;
    root = NULL;
    int opt;
    do {
        printf("1. Import data from text file\n");
        printf("2. Import data from dat file\n");
        printf("3. Add phone model\n");
        printf("4. Delete\n");
        printf("5. Update\n");
        printf("6. Searching\n");
        printf("7. Displaying\n");
        printf("8. Save data to file PhoneDB.dat\n");
        printf("9. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr1 = fopen("PhoneDB.txt", "r");
                if(fptr1 == NULL) printf("cannot open file\n");
                KeyType *s = (KeyType *)malloc(sizeof(KeyType));
                while(!feof(fptr1)) {
                    fscanf(fptr1, "%s %s %s %d", s->model, s->memo, s->screen, &s->price);
                    //KeyType tmp; 
                    //strcpy(tmp.model, s->model);
                    //strcpy(tmp.memo, s->memo);
                    //strcpy(tmp.screen, s->screen);
                    //tmp.price = s->price;
                    InsertNode(*s, &root);
                }
                fclose(fptr1);
                free(s);
                printf("Successful\n");
            }
            break;
            case 2: {
                FILE *fptr2 = fopen("PhoneDB.dat", "r+b");
                if(fptr2 == NULL) printf("cannot open file\n");
                KeyType *s = (KeyType *)malloc(sizeof(KeyType));
                while(!feof(fptr2)) {
                    fread(s, sizeof(KeyType), 1, fptr2);
                    KeyType tmp; 
                    strcpy(tmp.model, s->model);
                    strcpy(tmp.memo, s->memo);
                    strcpy(tmp.screen, s->screen);
                    tmp.price = s->price;
                    InsertNode(tmp, &root);
                }
                fclose(fptr2);
                free(s);
                printf("Successful\n");
            }
            break;
            case 3: {
                KeyType e = enterPhone();
                InsertNode(e, &root);
                printf("Successful\n");
            }
            break;
            case 4: {
                char s[40];
                printf("Enter the model to delete: ");
                fflush(stdin);
                gets(s);
                DeleteNode(s, &root);
                printf("Successful\n");
            }
            break;
            case 5: {
                printf("Successful\n");
            }
            break;
            case 6: {
                char s[40];
                printf("Enter the model to search: ");
                fflush(stdin);
                gets(s);
                displayNode(Search(s, root));
            }
            break;
            case 7: {
                printf("\n%-30s %-20s %-20s %-10s\n", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
                InorderPrint(root);
            }
            break;
            case 8: {
                FILE *fptr2 = fopen("PhoneDB.dat", "w+b");
                if(fopen == NULL) printf("cannot open file\n");
                ExportToFile(root, fptr2);
                fclose(fptr2);
                printf("Successful\n");
            }
            break;
            case 9: {
                printf("Exit\n");
                freeTree(root);
            }
            default:
            break;
        }
    }while(opt != 9);
    return 0;
}
