/*Create a text file AUOpen.txt containing the names of tennis players participating in
the Australian Open tournament, one player per line. 
The number of player is the power of 2 and a minimum of 16 people.
Build a tree describing the competition results until the final. 
Initially, the (16) opponents are leaf nodes, 
the winner will be stored at the parent node of a pair of players. 
The winner of a match is randomly selected.
Print the results of the matches (tree content) to the screen and the file treegame.txt*/
typedef char elmType;
#include"Tree.h"
#include<time.h>
elmType random(treeType a, treeType b) {
    srand((int)time(0));
    int win = rand();
    if(win % 2 == 0) return a->element;
    else return b->element;
}
void InorderPrint(treeType T) {
    if(T != NULL) {
        InorderPrint(T->left);
        printf("%30s\n", T->element);
        InorderPrint(T->right);
    }
}
void makeNull(treeType T) {
    T->element = '\0';
    makeNull(T->left);
    makeNull(T->right);
}
int main() {
    int i, count = 0;
    treeType root;
    root = NULL;
    FILE *fptr1 = fopen("AUOpen.txt", "r");
    if(fptr1 == NULL) printf("cannot open file\n");
    FILE *fptr2 = fopen("treegame.txt", "w+");
    if(fptr2 == NULL) printf("cannot open file\n");
    elmType *s = (elmType *)malloc(sizeof(elmType));
    while(!feof(fptr1)) {
        fscanf(fptr1, "%s", s);
        makeNode(*s);
        count++;
    }
    printf("%s %30s %30s %30s\n", "First Round", "Second Round", "Third Round", "Forth Round");
    InorderPrint(root);
    free(s);
    fclose(fptr1);
    return 0;
}