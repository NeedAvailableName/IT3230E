#include<stdlib.h>
#include<stdio.h>
typedef struct node_t {
    int element;
    struct node_t *next;
} StackType;

StackType *push(StackType *p, int value) {
    StackType *temp;
    temp = (StackType *)malloc(sizeof(StackType));
    if(temp == NULL) printf("Allocation failed\n");
    temp->element = value;
    temp->next = p;
    p = temp;
    return p;
}
StackType *pop(StackType *p, int *value) {
    StackType *temp;
    if(p == NULL) {
        printf("Stack is empty\n");
        return 0;
    }
    *value = p->element;
    temp = p;
    p = p->next;
    free(temp);
    return p;
}
