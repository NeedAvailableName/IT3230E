#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef int elementType;
struct node_t {
    elementType ele;
    struct node_t *next;
};
typedef struct node_t node;
typedef node* pos;
typedef struct {
    pos front, rear;
}Queue;
void makeNull(Queue *Q) {
    pos head;
    head = (pos)malloc(sizeof(pos));
    head->next = NULL;
    Q->front = head;
    Q->rear = head;
}
int isEmpty(Queue Q) {
    return (Q.front == NULL);
}
int isFull(Queue Q) {
    return (Q.rear == NULL);
}
void enQueue(elementType e, Queue *Q) {
    Q->rear->next = (pos)malloc(sizeof(pos));
    //if(Q->front == NULL) {
    //    Q->front = new;
    //    Q->rear = new;
    //}
    //else {
        Q->rear = Q->rear->next;
        Q->rear->ele = e;
        Q->rear->next = NULL;
    //}
}
void deQueue(Queue *Q) {
    if(isEmpty(*Q)) {
        printf("Queue is empty\n");
    }
    else {
        node *temp = Q->front;
        //elementType e = temp->ele;
        Q->front = temp->next;
        free(temp);
    }
}