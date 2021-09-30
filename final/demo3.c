typedef int elementType;
#include"queuelist.h"
int main() {
    Queue Q;
    makeNull(&Q);
    int i;
    for(i = 0; i < 10; i++) {
        enQueue(i, &Q);
    }
    deQueue(&Q);
    pos cur;
    for(cur = Q.front; cur != NULL; cur = cur->next) {
        printf("%d ", cur->ele);
    }
    return 0;
} 