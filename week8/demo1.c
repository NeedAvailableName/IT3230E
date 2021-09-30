#include<stdio.h>
#include<stdlib.h>
#include"genSLL.h"
typedef struct {
    char id[10];
    char name[40];
    int grade;
}student;

student readNode() {
    student tmp;
    printf("Enter the id: ");
    fflush(stdin);
    gets(tmp.id);
    fflush(stdin);
    printf("Enter the student name: ");
    gets(tmp.name);
    printf("Enter the grade: ");
    scanf("%d", &tmp.grade);
    return tmp;
}

void displayNode(node *p) {
    printf("%-20s %-40s %-10d\n", p->element.id, p->element.name, p->element.grade);
}

node *addStudent(node *root, node *newN) {
    node *cur, *prev = NULL;
    elementtype tmp;
    newN = makeNewNode(tmp);
    if(root == NULL) return newN;
    if(newN->element.grade > root->element.grade) {
        newN->next = root;
        return newN;
    }
    cur = root;
    while(cur != NULL && newN->element.grade < cur->element.grade) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = newN;
    newN->next = cur;
    return root;
}
node *find_student(node *root, char *id) {
    node *to_search = root;
    while(to_search != NULL) {
        if(strcmp(id, to_search->element.id) == 0) return to_search;
        to_search = to_search->next;
    }
    return NULL;
}

node *removeStudent(node *p, char *id) {
    p = root;
    while(cur != NULL && strcmp(cur->element.id, id) != 0) {
        prev = cur;
        cur = cur->next;
    }
    if(cur != NULL) {
        prev->next = cur->next;
        free(cur);
    }
    return root; 
}

node *changeGrade(node *root, char *id, int newGrade) {
    elementtype tmp;
    node *newN = makeNewNode(tmp);
    newN = find_student(root, id);
    root = removeStudent(root, id);
    return addStudent(root, newN);
}

int main() {
    int i;
    for(i = 0; i < 3; i++) {
        elementtype tmp;
        node *newN = makeNewNode(tmp);
        addStudent(root, newN);
    }
    char *id;
    printf("Enter the name for searching\n");
    gets(id);
    find_student(root, id);
    removeStudent(root, id);
    traversingList();
}