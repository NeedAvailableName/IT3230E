#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
// typedef int Eletype;
typedef struct queueRec{
    Eletype storage[MAX];
    int front;
    int rear;
}queueType;

void makeNullQueue(queueType *q){
    (*q).front = -1;
    (*q).rear = -1;
}

int queueEmpty(queueType q){
    return q.front == -1;
}

int queueFull(queueType q){
    return (q.rear - q.front + 1) % MAX == 0;
}

void enQueue(Eletype e, queueType *q){
    if(!queueFull(*q)){
        if(queueEmpty(*q))
            (*q).front = 0;
        (*q).rear = ((*q).rear + 1) % MAX;
        (*q).storage[(*q).rear] = e;
    }
    else{
        printf("Queue is full\n");
    }
}

Eletype deQueue(queueType *q){
    Eletype e;
    if(!queueEmpty(*q)){
        e = (*q).storage[(*q).front];
        (*q).front = ((*q).front + 1) % MAX;
        if((*q).front > (*q).rear){
            makeNullQueue(q);
        }
        return e;
    }
    else{
        printf("Queue is empty\n");
    }
}

int queueFrontMem(queueType queue){
    if(!queueEmpty(queue)){
        return queue.storage[queue.front].memo;
    }
}

int queueFrontID(queueType queue){
    if(!queueEmpty(queue)){
        return queue.storage[queue.front].ID;
    }
}

// int main(){
//     queueType q;
//     makeNullQueue(&q);
//     while(!isFull(q)){
//         enQueue(1, &q);
//         deQueue(&q);
//     }
// }