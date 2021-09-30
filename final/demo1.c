#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int num_customer = 0;
int num_cashier = 4;
struct Node_t {
    int ele;
    struct Node_t *next;
};
typedef struct Node_t Node;
typedef Node *singlelist;
typedef struct cashier_t {
    int num;
    singlelist Root, Cur, Prev;
}cashier;
singlelist makeNode(int e){
    singlelist new = (singlelist)malloc(sizeof(singlelist));
    new->ele = e;
    new->next = NULL;
    return new;
}
void insertTail(int e, singlelist *root, singlelist *cur, singlelist *prev) {
    singlelist new = makeNode(e);
    *cur = *root;
    while(*cur != NULL) {
        *cur = (*cur)->next;
    }
    new = (*cur)->next;
    *cur = new;
}
void deleteFirst(singlelist *root, singlelist *cur, singlelist *prev) {
    if(*root == NULL) {
        printf("Empty list\n");
        return;
    }
    singlelist del;
    del = *root;
    *root = del->next;
    *cur = *root;
    free(del);
}
typedef cashier elementType;
struct node_t{
    elementType element;
    struct node_t *next;
    struct node_t *prev;
};
typedef struct node_t node;
typedef node *doublelist;
/*
void Enter(int i, doublelist *root, doublelist *cur, doublelist *tail) {
    i+=1;
    enQueue(i, (*cur)->element.Q);
    printf("%d %d\n", i, (*cur)->element.num);
    if(*cur != *tail) *cur = (*cur)->next;
    else if(*cur == *tail) *cur = *root;
}
void AdvancedEnter(int i, doublelist *root, doublelist *cur, doublelist *tail) {
    //enQueue();
}
void Checkout(int i, doublelist *root, doublelist *cur, doublelist *tail) {
    for(*cur = *root; *cur != NULL; *cur = (*cur)->next) {
        if(i == (*cur)->element.num && !isEmpty(*(*cur)->element.Q)) {
            printf("%d\n", &(*cur)->element.Q->front);
            deQueue((*cur)->element.Q);
        }
        else if(isEmpty(*(*cur)->element.Q)) {
            printf("Empty\n");
        }
        else printf("Error\n");
    }
}
void CountInLine(int i, doublelist *root, doublelist *cur, doublelist *tail) {
    int count = 0;
    for(*cur = *root; *cur != NULL; *cur = (*cur)->next) {
        if(i = (*cur)->element.num) {
            pos tmp;
            for(tmp = (*cur)->element.Q->front; tmp != NULL; tmp = tmp->next) {
                count++;
            }
        }
        //else 
    }
    printf("%d\n", count);
}
void ListCustomer(int i, doublelist *root, doublelist *cur, doublelist *tail) {
    pos tmp;
    for(*cur = *root; *cur != NULL; *cur = (*cur)->next) {
        if(i == (*cur)->element.num) {
            for(tmp = (*cur)->element.Q->front; tmp != NULL; tmp = tmp->next) {
                printf("%d ", tmp->ele);
            }
        }
    }
    printf("\n");   
}
void CountAllLine(doublelist *root, doublelist *cur, doublelist *tail) {
    int count = 0;
    while(*cur != NULL) {
        
    }
    
}
void OpenCashier(doublelist *root, doublelist *cur, doublelist *tail) {
    elementType e;
    e.num = num_cashier++;
    e.Q = NULL;
    insertAtTail(e, root, cur, tail);
    printf("%d\n", e.num);
}
*/
doublelist makeNewNode(elementType e) {
    doublelist new = (doublelist)malloc(sizeof(node));
    new->element = e;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
void insertAtTail(elementType e, doublelist *root, doublelist *cur, doublelist *tail) {
    doublelist new = makeNewNode(e);
    if(*tail == NULL) {
        *root = new;
        *tail = new;
        *cur = *root;
        return;
    }
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    *cur = *tail;
}
void deleteFirstNode(doublelist *root, doublelist *cur, doublelist *tail) {
    if(*root == NULL) {
        printf("Empty list\n");
        return;
    }
    doublelist p = *root;
    if((*root)->next == NULL) {
        free(p);
        *root = NULL;
        *tail = NULL;
        *cur = NULL;
        return;
    }
    *root = (*root)->next;
    *cur = *root;
    (*root)->prev = NULL;
    free(p);
}
void deleteAtTail(doublelist *root, doublelist *cur, doublelist *tail) {
    if(*tail == NULL) {
        printf("Empty list\n");
        return;
    }
    doublelist p = *tail;
    if((*tail)->prev == NULL) {
        free(p);
        *root = NULL;
        *tail = NULL;
        *cur = NULL;
        return;
    }
    *tail = (*tail)->prev;
    *cur = *tail;
    (*tail)->next = NULL;
    free(p);
}
void deleteCurrentNode(doublelist *root, doublelist *cur, doublelist *tail) {
    if(*root == NULL) {
        printf("Empty list\n");
        return;
    }
    if(*cur == *root) {
        deleteFirstNode(root, cur, tail);
        return;
    }
    if(*cur == *tail) {
        deleteAtTail(root, cur, tail);
        return;
    }
    doublelist temp = *cur;
    *cur = (*cur)->prev;
    (*cur)->next = temp->next;
    temp->next->prev = *cur;
    free(temp);
}
void CloseCashier(int i, doublelist *root, doublelist *cur, doublelist *tail) {
    for(*cur = *root; *cur != NULL; *cur = (*cur)->next) {
        if(i == (*cur)->element.num) {
            deleteCurrentNode(root, cur, tail);
            printf("Close\n");
        }
        //else
    }
}
int main() {
    doublelist root = NULL;
    doublelist cur = NULL;
    doublelist tail = NULL;
    for(int i = 1; i <= 4; i++) {
        elementType e;
        e.num = i;
        e.Root = NULL;
        e.Cur = NULL;
        e.Prev = NULL;
        insertAtTail(e, &root, &cur, &tail);
    }
    cur = root;
    char str[50];
    while(1) {
        scanf("%s", str);
        if(strcmp(str, "***") == 0) break;
        if(strcmp(str, "$Enter") == 0) {
            //Enter(num_customer, &root, &cur, &tail);
            num_customer+=1;
            insertTail(num_customer, &cur->element.Root, &cur->element.Cur, &cur->element.Prev);
            printf("%d %d\n", num_customer, cur->element.num);
            if(cur != tail) cur = cur->next;
            else if(cur == tail) cur = root;
        }
        /*
        else if(strcmp(str, "$AdvancedEnter") == 0) {
            AdvancedEnter(num_customer, &root, &cur, &tail);
        }
        else if(strcmp(str, "$Checkout") == 0) {
            int cashier_number;
            scanf("%d", &cashier_number);
            Checkout(cashier_number, &root, &cur, &tail);
        }
        else if(strcmp(str, "$CountNumberCustomerInLine") == 0) {
            int line_number;
            scanf("%d", &line_number);
            CountInLine(line_number, &root, &cur, &tail);
        }
        else if(strcmp(str, "$ListCustomerInLine") == 0) {
            int line_number;
            scanf("%d", &line_number);
            ListCustomer(line_number, &root, &cur, &tail);
        }
        else if(strcmp(str, "$CountNumberCustomersInAllLines") == 0) {
            CountAllLine(&root, &cur, &tail);
        }
        else if(strcmp(str, "$OpenCashier") == 0) {
            OpenCashier(&root, &cur, &tail);
        }
        else if(strcmp(str, "$CloseCashier") == 0) {
            int cashier_number;
            scanf("%d", &cashier_number);
            CloseCashier(cashier_number, &root, &cur, &tail);
        }
        */
    }
    return 0;
}