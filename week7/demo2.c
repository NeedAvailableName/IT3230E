#include<stdio.h>
#include<stdlib.h>
typedef struct student_t {
    char id[10];
    char name[40];
    int grade;
    struct student_t *next;
} student;

student *add_student(student *root, student *to_add) {
    student *cur, *prev = NULL;
    if(root == NULL) {
        return to_add;
    }
    if(to_add->grade > root->grade) {
        to_add->next = root;
        return to_add;
    }
    cur = root;
    while (cur != NULL && to_add->grade < cur->grade) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = to_add;
    to_add->next = cur;
    return root;
}
int main() {
    
}