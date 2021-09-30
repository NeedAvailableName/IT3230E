#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
// typedef char Eltype2;
typedef struct stackTypeNode2{
    Eltype2 item;
    struct stackTypeNode2 *next;
}stackTypeNode2;

typedef stackTypeNode2* stackType2;

stackType2 makeNode2(Eltype2 e){
    stackType2 new;
    new = (stackType2)malloc(sizeof(stackTypeNode2));
    new->item = e;
    // strcpy(new->item, e);
    new->next = NULL;
    return new;
}

// Eltype enterItem(){
//     printf("")
// }

int isEmpty2(stackType2 s){
    return (s == NULL);
}

int countStack2(stackType2 s){
    stackType2 temp;
    temp = s;
    int n = 0;
    while(temp != NULL){
        n ++;
        temp = temp->next;
    }
    return n;
}

int isFull2(stackType2 s){
    return (countStack2(s) >= MAX);
}

void push2(Eltype2 e, stackType2 *s){
    stackType2 new = makeNode2(e);
    if(*s == NULL){
        *s = new;
        return;
    }

    if(countStack2(*s) >= MAX){
        printf("Stack overflow!\n");
        return;
    }
    new->next = *s;
    *s = new;
}

Eltype2 pop2(stackType2 *s){
    if(*s == NULL){
        printf("Stack underflow!\n");
        return '\0';
    }
    stackType2 new = *s;
    *s = (*s)->next;
    Eltype2 e;
    e = new->item;
    // strcpy(e, new->item);
    free(new);
    return e;
}

Eltype2 peek2(stackType2 *s){
    if(*s == NULL){
        printf("Stack empty\n");
        return '\0';
    }
    return (*s)->item;
}

void printStack2(stackType2 s){
    stackType2 temp = s;
    while(temp != NULL){
        printf("%c ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void freeStack2(stackType2 *s){
    if(*s == NULL)
        return;
    stackType2 temp = *s;
    while(*s != NULL){
        *s = (*s)->next;
        free(temp);
        temp = *s;
    }
}
