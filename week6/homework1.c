/*Make a improved version of PhoneDB Phone management program using linked list.
Here is the functionalities int the menu:
1. Import from text: read data from text file and build the list (using InsertAtHead)
2. Import from dat: read data from .dat file and built the list (using InsertAfterCurrentPos)
3. Display list: Display all elements, each element in a line
4. Search phone by Model
5. Search phone of which the price is under the value inputted
6. Export to dat: store information in linked list to PhoneDB.dat
7. Manual insertion (add data for a phone model)
Program should ask the insertion mode: before or after current position
8. Quit*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char model[40];
    char memory[10];
    char screen[10];
    long price;
} phone;
typedef struct node {
    phone data;
    struct node *next;
} node;
node *root, *cur, *prev;
phone *s;

node *makeNewNode(phone addr) {
    node *newN = (node *)malloc(sizeof(node));
    newN->data = addr;
    newN->next = NULL;
    return newN;
}

phone readNode() {
    phone tmp;
    printf("Enter the model: ");
    fflush(stdin);
    gets(tmp.model);
    fflush(stdin);
    printf("Enter the memory space: ");
    gets(tmp.memory);
    printf("Enter the screen size: ");
    gets(tmp.screen);
    printf("Enter the price: ");
    scanf("%ld", &tmp.price);
    return tmp;
}

void displayNode(node *p) {
    printf("%-30s %-20s %-20s %-10ld\n", p->data.model, p->data.memory, p->data.screen, p->data.price);
}

void insertAtHead(phone addr) {
    node *newN = makeNewNode(addr);
    newN->next = root;
    root = newN;
    cur = root;
}

void insertAfterCurrent(phone addr) {
    node *newN = makeNewNode(addr);
    if(root == NULL) {
        root = newN;
        cur = root;
        prev = NULL;
    }
    else {
        newN->next = cur->next;
        cur->next = newN;
        prev = cur;
        cur = newN;
    }
}

void insertBeforeCurrent(phone addr) {
    node *newN = makeNewNode(addr);
    if(cur == root) {
        insertAtHead(addr);
    }
    else if(root == NULL) {
        root = newN;
    }
    else {
        while(prev->next != cur) {
            prev = prev->next;
        }
        prev->next = newN;
        newN->next = cur;
        cur = newN;
    }
}

/*void traversingList() {
    node *p;
    for (p = root; p != NULL; p = p->next) {
        printf("%-5d %-30s %-20s %-20s %-10ld\n", i+1, p->data.model, p->data.memory, p->data.screen, p->data.price);
    }
}*/

void func1(FILE *fptr1) {
    root = NULL;
    cur = root;
    s = (phone *)malloc(sizeof(phone));
    while(!feof(fptr1)) {
        fscanf(fptr1, "%s %s %s %ld", s->model, s->memory, s->screen, &s->price);
        phone tmp;
        insertAtHead(tmp);
        strcpy(tmp.model, s->model);
        strcpy(tmp.memory, s->memory);
        strcpy(tmp.screen, s->screen);
        tmp.price = s->price;
    } 
    free(s);
}

void func2(FILE *fptr2) {
    root = NULL;
    cur = root;
    prev = NULL;
    s = (phone *)malloc(sizeof(phone));
    while(fread(s, sizeof(phone), 1, fptr2) != 0) {
        phone tmp;
        insertAfterCurrent(tmp); 
        strcpy(tmp.model, s->model);
        strcpy(tmp.memory, s->memory);
        strcpy(tmp.screen, s->screen);
        tmp.price = s->price;
    }
    free(s);
}

void func3() {
    int i = 0;
    printf("%-5s %-30s %-20s %-20s %-10s\n", "Num", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    node *p;
    for (p = root; p != NULL; p = p->next) {
        printf("%-5d %-30s %-20s %-20s %-10ld\n", i+1, p->data.model, p->data.memory, p->data.screen, p->data.price);
        i++;
    }
}

void func4() {
    int i = 0, k = 0;
    char model[40];
    printf("Enter the phone model for searching: ");
    gets(model);
    printf("%-5s %-30s %-20s %-20s %-10s\n", "Num", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    for (cur = root; cur != NULL; cur = cur->next) {
        if (strcmp(model, cur->data.model) == 0) {
            printf("%-5d %-30s %-20s %-20s %-10ld\n", i+1, cur->data.model, cur->data.memory, cur->data.screen, cur->data.price);
            k++;
        }
    }
    if(k == 0) {
        printf("No result\n");
    }
}

void func5() {
    long money;
    int i = 0, k = 0;
    printf("Enter the money value: ");
    scanf("%ld", &money);
    printf("%-5s %-30s %-20s %-20s %-10s\n", "Num", "Model", "Memory space (GB)", "Screen size (inches)", "Price");
    for(cur = root; cur != NULL; cur = cur->next) {
        if(cur->data.price < money) {
            printf("%-5d %-30s %-20s %-20s %-10ld\n", i+1, cur->data.model, cur->data.memory, cur->data.screen, cur->data.price);
            k++;
            i++;
        }
    }
    if(k == 0) {
        printf("No result\n");
    }
}

void func6(FILE * fptr2) {
    for(cur = root; cur != NULL; cur = cur->next) {
        s = (phone *)malloc(sizeof(phone));
        strcpy(s->model, cur->data.model);
        strcpy(s->memory, cur->data.memory);
        strcpy(s->screen, cur->data.screen);
        s->price =  cur->data.price;
        fwrite(s, sizeof(phone), 1, fptr2);
    }
    free(s);
}

void func7() {
    int i = 0, choice, pos;
    node *temp, *pretemp;
    phone tmp;
    printf("Enter current position: ");
    scanf("%d", &pos);
    for(temp = root; temp != NULL; temp = temp->next) {
        i++;
        if(i == pos) {
            printf("current position: %-5d %-30s %-20s %-20s %-10ld\n", i, temp->data.model, temp->data.memory, temp->data.screen, temp->data.price);
            prev = pretemp;
            cur = temp;
            break;
        }
        pretemp = temp;
    }
    printf("You want to insert 1.Before current position or 2.After current position: ");
    scanf("%d", &choice);
    if(choice == 1) {
        tmp = readNode();
        insertBeforeCurrent(tmp);
    }
    if(choice == 2) {
        tmp = readNode();
        insertAfterCurrent(tmp);
    }
}

int main() {
    int opt;
    do {
        printf("MENU\n");
        printf("1. Import from text\n");
        printf("2. Read from dat\n");
        printf("3. Read to screen\n");
        printf("4. Search phone by model\n");
        printf("5. Search phone by price\n");
        printf("6. Export to dat\n");
        printf("7. Manual insertion\n");
        printf("8. Quit\n");
        printf("Enter a option: ");
        scanf("%d", &opt);
        fflush(stdin);
        switch(opt) {
            case 1: {
                FILE *fptr1 = fopen("PhoneDB.txt", "r");
                if (fptr1 == NULL) {
                    printf("cannot open file\n");
                }
                else func1(fptr1);
                fclose(fptr1);
            }
            break;
            case 2: {
                FILE *fptr2 = fopen("PhoneDB.dat", "r+b");
                if (fptr2 == NULL) {
                    printf("cannot open file\n");
                }
                else func2(fptr2);
                fclose(fptr2);
            }
            break;
            case 3: func3();    
            break;
            case 4: func4();
            break;
            case 5: func5();
            break;
            case 6: {
                FILE *fptr2 = fopen("PhoneDB.dat", "w+b");
                if(fptr2 == NULL) {
                    printf("cannot open file\n");
                }
                else func6(fptr2);
                fclose(fptr2);
            }
            break;
            case 7: func7();
            break;
            case 8: printf("Quit\n");
            break;
            default:
            break;
        } 
    } while(opt != 8);
    return 0;
}