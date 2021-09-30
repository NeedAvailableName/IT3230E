/*Simulate a computer that process computing request from OS's programs.
Configuration input:
- Number of parallel process it can run
- Memory capacity
Program has the menu:
- Create new program (with a given amount of necessary memory and ID)
- Kill a program
- Show the status of running and waiting processes.*/
int usedMem = 0;
int totalPro = 0;
int process;
int memory;
#include"genDLL.h"
#include"queueCir.h"
void create(Eletype program, doublelist *root, doublelist *tail, doublelist *cur, queueType *queue) {
    if(totalPro >= process) {
        printf("Maximum number of parallel processes %d\n", process);
        enQueue(program, queue);
        return;
    }
    if(memory - program.memo - usedMem >= 0) {
        usedMem += program.memo;
        insertAtTail(program, root, tail, cur);
        totalPro++;
        printf("Successful!\n");
        return;
    }
    else {
        enQueue(program, queue);
        printf("In queue as there is not enough memory (%d vs %d)\n", memory - usedMem, program.memo);
    }
}

void kill(int id, doublelist *root, doublelist *tail, doublelist *cur, queueType *queue) {
    deleteID(id, root, tail, cur);
    totalPro --;
    while(totalPro < process && !queueEmpty(*queue) && memory - usedMem - queueFrontMem(*queue) >= 0) {
        Eletype program = deQueue(queue);
        usedMem += program.memo;
        insertAtTail(program, root, tail, cur);
        totalPro ++;
    }
}

void printStatus(doublelist root, doublelist tail, queueType queue) {
    printf("Number of parallel programs: %d\n", process);
    printf("Memory capacity: %dMB\n", memory);
    printf("\n%-5s %-15s %-15s\n", "ID", "Memory (MB)", "Queue");
    doublelist temp = root;
    while(temp != NULL) {
        printf("%-5d %-15d %-15s\n", temp->element.ID, temp->element.memo, " ");
        temp = temp->next;
    }
    if(!queueEmpty(queue)) {
        for(int i = queue.front; i <= queue.rear; i++) {
            printf("%-5d %-15s %-15d\n", queue.storage[i].ID," ", queue.storage[i].memo);
        }
    }
}

int main() {
    printf("Enter the number of parallel process it can run: ");
    scanf("%d", &process);
    printf("Enter the memory capacity: ");
    scanf("%d", &memory);
    doublelist root = NULL, tail = NULL, cur = NULL;
    queueType q;
    makeNullQueue(&q);
    int opt;
    int id;
    do {
        printf("\n");
        printf("1. Create new program\n");
        printf("2. Kill a program\n");
        printf("3. Show the status of running and waiting processes\n");
        printf("4. Exit.\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                create(enterProgram(), &root, &tail, &cur, &q);
            }
            break;
            case 2: {
                printf("Enter program ID: ");
                scanf("%d", &id);
                kill(id, &root, &tail, &cur, &q);
            }    
            break;
            case 3: {
                printStatus(root, tail, q);
            }    
            break;
            case 4: {
                printf("Exit\n");
                freeAll(&root, &tail, &cur);
                makeNullQueue(&q);
            }    
            break;
            default:
            break;
        }
    }while(opt != 4);
}