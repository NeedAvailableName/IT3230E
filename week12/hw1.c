/*Create a text file AUOpen.txt containing the names of tennis players participating in
the Australian Open tournament, one player per line. 
The number of player is the power of 2 and a minimum of 16 people.
Build a tree describing the competition results until the final. 
Initially, the (16) opponents are leaf nodes, 
the winner will be stored at the parent node of a pair of players. 
The winner of a match is randomly selected.
Print the results of the matches (tree content) to the screen and the file treegame.txt*/

#include<limits.h>
#include<time.h>
#include<math.h>
typedef char* elmType;
#include"Tree.h"
typedef char* elementType;
#include"DLL.h"

elmType winner(treeType a, treeType b){
    int win = rand() % 100;
    if(win % 2 == 0)
        return a->element;
    return b->element;
}
void genFullTree(treeType *T, int n) {
    if(n == 0) return;
    else {
        *T = makeNode('\0');
        genFullTree(&(*T)->left, n-1);
        genFullTree(&(*T)->right, n-1);
    }
}
void insertPlayer(doublelist *root, doublelist *tail, doublelist *cur, treeType *T){
    if(isLeaf(*T)) {
        (*T)->element = (*root)->element;
        *root = (*root)->next;
        return;
    }
    if(*root == *tail)
        return;
    insertPlayer(root, tail, cur, &(*T)->left);
    insertPlayer(root, tail, cur, &(*T)->right);
    (*T)->element = winner((*T)->left, (*T)->right);
}

char *fix(char *a){
    int i = 0;
    while(a[i] != '\0'){
        if(a[i] == '\n')
            a[i] = '\0';
        i ++;
    }
    return a;
}

void inputToTree(treeType *T, FILE *f){
    doublelist root, tail, cur;
    root = NULL;
    tail = NULL;
    cur = NULL;
    int i = 0;
    while(!feof(f)){
        elmType name = (elmType)malloc(30 * sizeof(char));
        fgets(name, 30, f);
        // int i;
        name = fix(name);
        insertAtTail(name, &root, &tail, &cur);
        // printf("%d %s\n", i, cur->element);
        i ++;
    }
    fclose(f);
    genFullTree(T, (int) log2(i) + 1);
    insertPlayer(&root, &tail, &cur, T);
    printf("Successful\n");
    // inorderPrint(*t);
}

void printResult(treeType T){
    // printf("%-20s %-20s %-20s %-20s %-20s\n", "First round", "Second round", "Third round", "Semi-final round", "Final round");
    if(T == NULL)
        return;
    printResult(T->left);
    for(int i = 1; i < height(T); i ++){
        printf("%-25s ", " ");
    }
    printf("%-25s ", T->element);
    printf("\n");
    printResult(T->right);
}
void exportToFile(treeType T, FILE *fptr) {
    if(T != NULL) {
        exportToFile(T->left, fptr);
        for(int i = 1; i < height(T); i++) {
            fprintf(fptr, "%-25s ", " ");
        }
        fprintf(fptr, "%-25s \n", T->element);
        exportToFile(T->right, fptr);
    }
}
int main(){
    treeType tree;
    tree = NULL;
    FILE *f;
    int menu;
    srand((int) time(0));
    do {
        printf("\n1. Import from txt\n");
        printf("2. Print to screen\n");
        printf("3. Export to treegame.txt\n");
        printf("4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                if( (f = fopen("AUOpen.txt", "r")) == NULL){
                    printf("Cannot open: %s\n", "AUOpen.txt");
                    break;
                }
                inputToTree(&tree, f);
                break;
            case 2:
                printf("\n%-25s %-25s %-25s %-25s %-25s\n\n", "First round", "Second round", "Semi-final round", "Final round", "Champion");
                printResult(tree);
                break;
            case 3: {
                FILE *fptr = fopen("treegame.txt", "w");
                if(fptr == NULL) printf("cannot open file\n");
                exportToFile(root, fptr);
                fclose(fptr);
                printf("Successful\n");
            }
            break;
            case 4:
                freeTree(tree);
                break;
            default: {
                printf("Exit\n");
            }
                break;
        }
    }while(menu != 4);
}