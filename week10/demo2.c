#include"queue.h"
int main() {
    Queue Q;
    makeNull(&Q);
    while(!isFull(Q)) {
        enQueue(1, &Q);
        printf("%d ", DeQueue(&Q));
    }
}