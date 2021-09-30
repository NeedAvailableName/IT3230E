#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
// typedef char Eltype;
typedef struct stackTypeNode{
    Eltype item;
    struct stackTypeNode *next;
}stackTypeNode;

typedef stackTypeNode* stackType;

stackType makeNode(Eltype e){
    stackType new;
    new = (stackType)malloc(sizeof(stackTypeNode));
    new->item = e;
    new->next = NULL;
    return new;
}

// Eltype enterItem(){
//     printf("")
// }

int isEmpty(stackType s){
    return (s == NULL);
}

int countStack(stackType s){
    stackType temp;
    temp = s;
    int n = 0;
    while(temp != NULL){
        n ++;
        temp = temp->next;
    }
    return n;
}

int isFull(stackType s){
    return (countStack(s) >= MAX);
}

void push(Eltype e, stackType *s){
    stackType new = makeNode(e);
    if(*s == NULL){
        *s = new;
        return;
    }

    if(countStack(*s) >= MAX){
        printf("Stack overflow!\n");
        return;
    }
    new->next = *s;
    *s = new;
}

Eltype pop(stackType *s){
    if(*s == NULL){
        printf("Stack underflow!\n");
        return -999999;
    }
    stackType new = *s;
    *s = (*s)->next;
    Eltype e = new->item;
    free(new);
    return e;
}

Eltype peek(stackType *s){
    if(*s == NULL){
        printf("Stack empty\n");
        return '\0';
    }
    return (*s)->item;
}

void printStack(stackType s){
    stackType temp = s;
    while(temp != NULL){
        printf("%c ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void freeStack(stackType *s){
    if(*s == NULL)
        return;
    stackType temp = *s;
    while(*s != NULL){
        *s = (*s)->next;
        free(temp);
        temp = *s;
    }
}
