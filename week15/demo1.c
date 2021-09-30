/*#include<stdio.h>
#include<stdlib.h>
#define MAX_CHAR 10
#define TABLE_SIZE 13
typedef struct {
    char key[MAX_CHAR];
}element;
element hash_table[TABLE_SIZE];
void init_table(element ht[]) {
    int i;
    for(i = 0; i < TABLE_SIZE; i++) {
        ht[i].key[0] = NULL;
    }
}
int hash(char *key) {
    return (transform(key) % TABLE_SIZE);
}
int transform(char *key) {
    int number = 0;
    while(*key) number += *key++;
    return number;
}
#define B 10
typedef int KeyType;
typedef struct Node {
    KeyType Key;
    struct Node *Next;
}Node;
typedef Node *Position;
typedef Position Dictionary[B];
Dictionary D;
int H(KeyType x) {
    return (x % B);
}
void MakeNullSet(Dictionary D) {
    int i;
    for(i = 0; i < B; i++) D[i] = NULL;
}
int Search(KeyType x) {
    Position P;
    int Found = 0;
    P = D[H(x)];
    while((P != NULL) && (!Found)) {
        if(P->Key == x) Found = 1;
        else P = P->Next;
    }
    return Found;
}
void InsertSet(KeyType x) {
    int Bucket;
    Position P;
    if(!Search(x)) {
        Bucket = H(x);
        P = D[Bucket];
        D[Bucket] = (Node *)malloc(sizeof(Node));
        D[Bucket]->Key = x;
        D[Bucket]->Next = P;
    }
}
void DeleteSet(KeyType x) {
    int Bucket, Done;
    Position P, Q;
    Bucket = H(x);
    if(D[Bucket] != NULL) {
        if(D[Bucket]->Key == x) {
            Q = D[Bucket];
            D[Bucket] = D[Bucket]->Next;
            free(Q);
        }
        else {
            Done = 0;
            P = D[Bucket];
            while((P->Next != NULL) && (!Done)) {
                if(P->Next->Key == x) Done = 1;
                else P = P->Next;
            }
            if(Done) {
                Q = P->Next;
                P->Next = Q->Next;
                free(Q);
            }
        }
    }
}
int emptybucket(int b) {
    return (D[b] == NULL ? 1:0);
}
int empty() {
    int b;
    for(b = 0; b < B; b++) {
        if(D[b] != NULL) return 0;
        else return 1;
    }
}
void clearbucket(int b) {
    Position p, q;
    q = NULL;
    p = D[b];
    while(p != NULL) {
        q = p;
        p = p->Next;
        free(q);
    }
    D[b] = NULL;
}
void clear() {
    int b;
    for(b = 0; b < B; b++) {
        clearbucket(b);
    }
}
void traversebucket(int b) {
    Position p;
    p = D[b];
    while(p != NULL) {
        printf("%d ", p->Key);
        p = p->Next;
    }
}
void traverse() {
    int b;
    for(b = 0; b < B; b++) {
        printf("Bucket %d: ", b);
        traversebucket(b);
        printf("\n");
    }
}
int main() {
    Dictionary d;
    MakeNullSet(d);
    int i;
    for(i = 0 ;i < 100; i++) {
        InsertSet(i);
    }
    //traversebucket(1);
    if(Search(88)) printf("In the bucket\n");
    else printf("No result\n");
    InsertSet(100);
    //DeleteSet(100);
    traverse();
    clear();
}*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct NODE {
	int data;
	struct NODE *left;
	struct NODE *right;
}node;
//node *r = NULL;
node *createTreeNode(int x) {
	node *p = (node *)malloc(sizeof(node));
	p->data = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
node *addTreeNode(node *r, int x) {
	node *p = createTreeNode(x);
	if(r == NULL) {
		r = p;
        return r;
	}
	if(x < r->data) r->left = addTreeNode(r->left, x);
	if(x >= r->data) r->right = addTreeNode(r->right, x);
	return r;
}
void input(node *r) {
	char cmd[20];
	while(1) {
		scanf("%s", cmd);
		if(strcmp(cmd, "$insert") == 0) {
			int x;
			printf("add number: ");
			scanf("%d", &x);
            r = addTreeNode(r, x);
		}
		else if(strcmp(cmd, "#") == 0) break;
	}
}
void printInOrder(node *r) {
	if(r != NULL) {
		printf("%d ", r->data);
		printInOrder(r->left);
		printInOrder(r->right);
	}
}
int main() {
    node *r = NULL;
	input(r);
	printInOrder(r);
	return 0;
}