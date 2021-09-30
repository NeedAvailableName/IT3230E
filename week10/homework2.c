/*Simulate a computer that process computing request from OS's programs.
Configuration input:
- Number of parallel process it can run
- Memory capacity
Program has the menu:
- Create new program (with a given amount of necessary memory and ID)
- Kill a program
- Show the status of running and waiting processes.
typedef struct process {
    int ID;
    int memo;
} process;
typedef process elementType;
#include"queuelist.h"
Queue *P, *Q;
int memory, pro;

void func1(elementType a) {
    printf("Enter the process ID: ");
    scanf("%d", &a.ID);
    printf("Enter the process memory: ");
    scanf("%d", &a.memo);
    enQueue(a, &Q);
    if(isEmpty(*P)) {
        enQueue(a, &P);
        deQueue(&Q);
    }
}
void func2(Queue *P, Queue *Q) {
    deQueue(&P);
    pos p;
    int num_process = 0, num_memory = 0;
    for(p = P.front; p != NULL; p = p->next) {
        num_process++;
        num_memory += p;
    }
    pos tmp;
    for(tmp = Q.front; tmp != NULL; tmp = tmp->next) {
        if(num_process < memory && (memory - num_memory - tmp->elementType->memo > 0)) {
            enQueue(tmp, &P);
        }
    }
}
void func3(Queue *P, Queue *Q) {
    printf("ID\tMemory\tQueue\n");
    pos p;
    for(p = P.front; p != NULL; p = p->next) {
        printf("%d\t%d\n", p->elementType->ID, p->elementType->memo);
    }
    pos q;
    for(q = Q->front; q != NULL; q = q->next) {
        printf("%d\t\t%d\n", q->elementType->ID, q->elementType->memo);
    }
}
int main() {
    int opt;
    makeNull(&P);
    makeNull(&Q);
    printf("Enter the parallel process it can run: ");
    scanf("%d", &pro);
    printf("Enter the memory capacity: ");
    scanf("%d", &memory);
    do {
        printf("\n");
        printf("1. create new program\n");
        printf("2. kill a program\n");
        printf("3. show the status of running and waitting processes\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                elementType a;
                func1(a);
            }
            break;
            case 2: {
                func2(P, Q);
            }
            break;
            case 3: {
                func3(P, Q);
            }
            break;
            case 4: printf("Exit\n");
            break;
            default:
            break;
        }
    } while (opt != 4);
    return 0;
}*/
int usedMem = 0;
int totalPro = 0;
typedef struct storage {
    int ID;
    int memo;
} storage;
#include"DLL.h"
#include"queue.h"
void create(elementType program, doublelist *root, doublelist *tail, doublelist *cur, Queue *queue){
    if(totalPro >= 5){
        printf("Maximum number of parallel processes (5)\n");
        enQueue(program, queue);
        return;
    }
    // printf("Check\n");
    if(MAX - program.memo - usedMem >= 0){
        usedMem += program.memo;
        insertAtTail(program, root, tail, cur);
        totalPro ++;
        printf("Successful!\nProcess created\n");
        return;
    }
    else{
        enQueue(program, queue);
        printf("In queue as there is not enough memory (%d vs %d)\n", MAX - usedMem, program.memo);
    }
}

void kill(int id, doublelist *root, doublelist *tail, doublelist *cur, Queue *queue){
    deleteID(id, root, tail, cur);
    totalPro --;
    while(totalPro < 5 && !queueEmpty(*queue) && MAX - usedMem - queueFrontMem(*queue) >= 0){
        elementType program = deQueue(queue);
        usedMem += program.memo;
        insertAtTail(program, root, tail, cur);
        totalPro ++;
    }
}

void printStatus(doublelist root, doublelist tail, Queue queue){
    printf("Number of parallel programs: 5\n");
    printf("Memory capacity: 100MB\n");
    printf("\n%-5s %-15s %-15s\n", "ID", "Memory (MB)", "Queue");
    doublelist temp = root;
    while(temp != NULL){
        printf("%-5d %-15d %-15s\n", temp->elementType.ID, temp->elementType.memo, " ");
        temp = temp->next;
    }
    if(!queueEmpty(queue))
        for(int i = queue.front; i <= queue.rear; i ++){
        printf("%-5d %-15s %-15d\n", queue.storage[i].ID," ", queue.storage[i].memo);
        }
}

void printMenu(){
    printf("\n------Menu------\n");
    printf("\n1. Create new program.\n");
    printf("2. Kill a program.\n");
    printf("3. Show status of programs.\n");
    printf("4. Exit.\n");
    printf("\nEnter choice: ");
}

int main(){
    doublelist root = NULL, tail = NULL, cur = NULL;
    Queue q;
    makeNull(&q);
    int menu;
    int id;
    do{
        printMenu();
        scanf("%d", &menu);
        switch(menu){
            case 1:
                elementType e;
                create(e, &root, &tail, &cur, &q);
                break;
            case 2:
                printf("Enter program ID: ");
                scanf("%d", &id);
                kill(id, &root, &tail, &cur, &q);
                break;
            case 3:
                printStatus(root, tail, q);
                break;
            case 4:
                freeAll(&root, &tail, &cur);
                makeNull(&q);
                break;
            default:
                break;
        }
    }while(menu != 4);
}

