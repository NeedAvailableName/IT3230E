#include<stdio.h>
#include<stdlib.h>
#define MAX 100
//typedef int elementType;
typedef struct Queue {
    elementType storage[MAX];
    int front;
    int rear;
} Queue;
void initialize(Queue *Q) {
    (*Q).front = 0;
}
void makeNull(Queue *Q) {
    Q->front = -1;
    Q->rear = -1;
}
int isEmpty(Queue Q) {
    return Q.front == -1;
}
int isFull(Queue Q) {
    return (Q.rear == MAX - 1);
}
int IsFull(Queue Q) {
    return (Q.rear - Q.front + 1) % MAX == 0;
}
void enQueue(elementType e, Queue *Q) {
    if(!isFull(*Q)) {
        if(isEmpty(*Q)) Q->front = 0;
        Q->rear = Q->rear + 1;
        Q->storage[Q->rear] = e;
    }
    else {
        printf("Queue is full\n");
    }
}
void EnQueue(elementType e, Queue *Q) {
    if(IsFull(*Q)) {
        printf("Queue is full\n");
    }
    else {
        if(isEmpty(*Q)) Q->front = 0;
        Q->rear = (Q->rear + 1) % MAX;
        Q->storage[Q->rear] = e;
    }
}
elementType deQueue(Queue *Q) {
    if(isEmpty(*Q)) {
        printf("Q is empty\n");
    }
    else {
        elementType e;
        e = Q->storage[Q->front];
        Q->front = Q->front++;
        if(Q->front > Q->rear) makeNull(Q);
        return e;
    }
}
elementType DeQueue(Queue *Q) {
    elementType e;
    if(!isEmpty(*Q)) {
        e = Q->storage[Q->front];
        if(Q->front == Q->rear) {
            makeNull(Q);
        }
        else Q->front = (Q->front + 1) % MAX;
        return e;
    }
    else printf("Queue is empty\n");
}