#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
int num_cashier = 4;
int num_customer = 0;
struct Node_t {
    int ele;
    struct Node_t *next;
    struct Node_t *prev;
};
typedef struct Node_t Node;
typedef Node *doublelist1;
typedef struct cashier_t {
    int num;
    doublelist1 root1, cur1, tail1;
}cashier;
typedef cashier elementType;
struct node_t{
    elementType element;
    struct node_t *next;
    struct node_t *prev;
};
typedef struct node_t node;
typedef node *doublelist2;
doublelist1 makeNode(int e) {
    doublelist1 new = (doublelist1)malloc(sizeof(Node));
    new->ele = e;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
void insertTail(int e, doublelist1 *root1, doublelist1 *cur1, doublelist1 *tail1) {
    doublelist1 new = makeNode(e);
    if(*tail1 == NULL) {
        *root1 = new;
        *tail1 = new;
        *cur1 = *root1;
        return;
    }
    (*tail1)->next = new;
    new->prev = *tail1;
    *tail1 = new;
    *cur1 = *tail1;
}
void deleteFirst(doublelist1 *root1, doublelist1 *cur1, doublelist1 *tail1) {
    if(*root1 == NULL) {
        printf("Empty list\n");
        return;
    }
    doublelist1 p = *root1;
    if((*root1)->next == NULL) {
        free(p);
        *root1 = NULL;
        *tail1 = NULL;
        *cur1 = NULL;
        return;
    }
    *root1 = (*root1)->next;
    *cur1 = *root1;
    (*root1)->prev = NULL;
    free(p);
}

doublelist2 makeNewNode(elementType e) {
    doublelist2 new = (doublelist2)malloc(sizeof(node));
    new->element = e;
    new->next = NULL;
    new->prev = NULL;
    return new;
}
void insertAtTail(elementType e, doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    doublelist2 new = makeNewNode(e);
    if(*tail2 == NULL) {
        *root2 = new;
        *tail2 = new;
        *cur2 = *root2;
        return;
    }
    (*tail2)->next = new;
    new->prev = *tail2;
    *tail2 = new;
    //*cur2 = *tail2;
}
void deleteFirstNode(doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    if(*root2 == NULL) {
        printf("Empty list\n");
        return;
    }
    doublelist2 p = *root2;
    if((*root2)->next == NULL) {
        free(p);
        *root2 = NULL;
        *tail2 = NULL;
        *cur2 = NULL;
        return;
    }
    *root2 = (*root2)->next;
    //*cur2 = *root2;
    (*root2)->prev = NULL;
    free(p);
}
void deleteAtTail(doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    if(*tail2 == NULL) {
        printf("Empty list\n");
        return;
    }
    doublelist2 p = *tail2;
    if((*tail2)->prev == NULL) {
        free(p);
        *root2 = NULL;
        *tail2 = NULL;
        *cur2 = NULL;
        return;
    }
    *tail2 = (*tail2)->prev;
    //*cur2 = *tail2;
    (*tail2)->next = NULL;
    free(p);
}
int FindMin(doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    int min = INT_MAX;
    doublelist2 temp;
    for(temp = *root2; temp != NULL; temp = temp->next) {
        doublelist1 tmp;
        int count = 0;
        for(tmp = temp->element.root1; tmp != NULL; tmp = tmp->next) {
            count++;
        }
        if(min > count) min = count;
    }
    return min;
}
void Checkout(int i, doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    bool flag = false;
    doublelist2 temp = *root2;
    for(temp = *root2; temp != NULL; temp = temp->next) {
        if(i == temp->element.num && temp->element.root1 != NULL) {
            printf("%d\n", temp->element.root1->ele);
            deleteFirst(&temp->element.root1, &temp->element.cur1, &temp->element.tail1);
            flag = true;
        }
        else if(i == temp->element.num && temp->element.root1 == NULL) {
            printf("Empty\n");
            flag = true;
        }
    }
    if(flag == false) printf("Error\n");
}
void CountInLine(int i, doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    int count = 0;
    bool flag = false;
    doublelist2 temp;
    for(temp = *root2; temp != NULL; temp = temp->next) {
        if(i == temp->element.num) {
            flag = true;
            doublelist1 tmp;
            for(tmp = temp->element.root1; tmp != NULL; tmp = tmp->next) {
                count++;
            }
        }
    }
    if(flag == false) printf("Error\n"); 
    else if(count > 0) printf("%d\n", count);
    else printf("\n");
}
void ListCustomer(int i, doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    doublelist2 temp;
    bool flag = false;
    for(temp = *root2; temp != NULL; temp = temp->next) {
        if(i == temp->element.num) {
            doublelist1 tmp;
            flag = true;
            for(tmp = temp->element.root1; tmp != NULL; tmp = tmp->next) {
                printf("%d ", tmp->ele);
            }
        }
    }
    if(flag == false) printf("Error");
    printf("\n");   
}
void CountAllLine(doublelist2 *root2, doublelist2 *cur2, doublelist2 *tail2) {
    int count = 0;
    doublelist2 temp;
    for(temp = *root2; temp != NULL; temp = temp->next) {
        doublelist1 tmp;
        for(tmp = temp->element.root1; tmp != NULL; tmp = tmp->next) {
            count++;
        }
    }
    printf("%d\n", count);
}
int main() {
    doublelist2 root2 = NULL;
    doublelist2 cur2 = NULL;
    doublelist2 tail2 = NULL;
    for(int i = 1; i <= 4; i++) {
        elementType e;
        e.num = i;
        e.root1 = NULL;
        e.cur1 = NULL;
        e.tail1 = NULL;
        insertAtTail(e, &root2, &cur2, &tail2);
    }
    cur2 = root2;
    char str[50];
    while(1) {
        scanf("%s", str);
        if(strcmp(str, "***") == 0) {
            doublelist2 temp;
            for(temp = root2; temp != NULL; temp = temp->next) {
                deleteFirstNode(&root2, &cur2, &tail2);
            }
            break;
        }
        if(strcmp(str, "$Enter") == 0) {
            num_customer+=1;
            insertTail(num_customer, &cur2->element.root1, &cur2->element.cur1, &cur2->element.tail1);
            printf("%d %d\n", num_customer, cur2->element.num);
            if(cur2 != tail2) cur2 = cur2->next;
            else if(cur2 == tail2) cur2 = root2;
        }
        else if(strcmp(str, "$AdvancedEnter") == 0) {
            int min = FindMin(&root2, &cur2, &tail2);
            doublelist2 temp = root2;
            while(temp != NULL) {
                doublelist1 tmp;
                int count = 0;
                for(tmp = temp->element.root1; tmp != NULL; tmp = tmp->next) {
                    count++;
                }
                if(count == min) {
                    num_customer+=1;
                    insertTail(num_customer, &temp->element.root1, &temp->element.cur1, &temp->element.tail1);
                    break;
                }
                else temp = temp->next;
            }
            printf("%d %d\n", num_customer, temp->element.num);
        }
        else if(strcmp(str, "$Checkout") == 0) {
            int cashier_number;
            scanf("%d", &cashier_number);
            Checkout(cashier_number, &root2, &cur2, &tail2);
        }
        else if(strcmp(str, "$CountNumberCustomerInLine") == 0) {
            int line_number;
            scanf("%d", &line_number);
            CountInLine(line_number, &root2, &cur2, &tail2);
        }
        else if(strcmp(str, "$ListCustomerInLine") == 0) {
            int line_number;
            scanf("%d", &line_number);
            ListCustomer(line_number, &root2, &cur2, &tail2);
        }
        else if(strcmp(str, "$CountNumberCustomerInAllLines") == 0) {
            CountAllLine(&root2, &cur2, &tail2);
        }
        else if(strcmp(str, "$OpenCashier") == 0) {
            elementType e;
            e.num = num_cashier+=1;
            e.root1 = NULL;
            e.cur1 = NULL;
            e.tail1 = NULL;
            insertAtTail(e, &root2, &cur2, &tail2);
            if(cur2 == root2) cur2 = tail2;
            printf("%d\n", e.num);
        }
        else if(strcmp(str, "$CloseCashier") == 0) {
            int cashier_number, count_cashier = 0;
            doublelist2 temp;
            scanf("%d", &cashier_number);
            for(temp = root2; temp != NULL; temp = temp->next) {
                count_cashier++;
            }
            if(count_cashier <= 1) printf("Error\n");
            else {
                bool flag = false;
                for(temp = root2; temp != NULL; temp = temp->next) {
                    if(cashier_number == temp->element.num) {
                        doublelist1 root3 = NULL;
                        doublelist1 cur3 = NULL;
                        doublelist1 tail3 = NULL;
                        int count_customer = 0;
                        flag = true;
                        doublelist1 tmp;
                        for(tmp = temp->element.root1; tmp != NULL; tmp = tmp->next) {
                            count_customer++;
                            insertTail(tmp->ele, &root3, &cur3, &tail3);
                        }
                        if(cur2 == temp && cur2 != tail2) {
                            cur2 = temp->next;
                        }
                        else if(cur2 == temp && cur2 == tail2) {
                            cur2 = root2;
                        }
                        if(temp == root2) {
                            deleteFirstNode(&root2, &cur2, &tail2);
                            cur2 = root2;
                        }
                        else if(temp == tail2) deleteAtTail(&root2, &cur2, &tail2);
                        else {
                            doublelist2 t;
                            t = temp->prev;
                            temp->next->prev = t;
                            t->next = temp->next;
                            free(temp);
                        }
                        if(count_customer == 0 && cur2 != root2) {
                            if(cur2 != tail2) cur2 = cur2->next;
                            else if(cur2 == tail2) cur2 = root2;
                        }
                        if(count_customer != 0) {
                            for(tmp = root3; tmp != NULL; tmp = tmp->next) {
                                insertTail(tmp->ele, &cur2->element.root1, &cur2->element.cur1, &cur2->element.tail1);
                                if(cur2 != tail2) cur2 = cur2->next;
                                else if(cur2 == tail2) cur2 = root2;
                            }
                        }
                        printf("Closed\n");
                    }
                }
                if(flag == false) printf("Error\n");
            }  
        }
    }
}