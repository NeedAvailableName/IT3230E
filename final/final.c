typedef struct class_t {
    char class_code[10];
    char course_code[10];
    char schedule[20];
}class;
typedef class elementType;
#include"SLL.h"

int main() {
    singlelist root, cur, prev;
    root = NULL;
    cur = NULL;
    prev = NULL; 
    int opt;
    do {
        printf("1. Read file\n");
        printf("2. Traversal the list\n");
        printf("3. Search classes\n");
        printf("4. Delete class\n");
        printf("5. Order classes\n");
        printf("6. Count classes\n");
        printf("7. Exit\n");
        printf("Enter your option\n");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                FILE *fptr = fopen("Schedule.txt", "r");
                while(!feof(fptr)) {
                    elementType *s = (elementType *)malloc(sizeof(elementType));
                    fscanf(fptr, "%s\n", s->class_code);
                    fscanf(fptr, "%s\n", s->course_code);
                    fgets(s->schedule, 30, fptr);
                    fflush(stdin);
                    insertAtHead(*s, &root, &cur, &prev);
                }
                fclose(fptr);
            }
            break;
            case 2: {
                *cur = *root;
                printf("%-10s %-10s %-10s\n", "Class", "Course", "Schedule");
                while(*cur != NULL) {
                    printf("%-10s %-10s %-10s\n", (*cur)->element.class_code, (*cur)->element.course_code, (*cur)->element.schedule);
                    *cur = (*cur)->next;
                }
            }
            break;
            case 3: {
                char course[10];
                *cur = *root;
                while(*cur != NULL) {
                    if(strcmp((*cur)->element.course_code, course) == 0) {
                        printf("%-10s %-10s %-10s\n", (*cur)->element.class_code, (*cur)->element.course_code, (*cur)->element.schedule);
                    }
                    else *cur = (*cur)->next;
                }
            }
            break;
            case 4: {
                char class[10];
                *cur = *root;
                while(*cur != NULL) {
                    if(strcmp((*cur)->element.class_code, class) == 0) {
                        deleteCurrentNode(&root, &cur, &prev);
                    }
                    else {
                        *cur = (*cur)->next;
                    }
                }
            }
            break;
            case 5: {
                singlelist *root1, *cur1, *prev1;
                *root1 = NULL;
                *cur1 = NULL;
                *prev1 = NULL;
                *cur = *root;
                insertAtHead((*cur)->element, &root1, &cur1, &prev1);
                while(*cur != NULL) {
                    for(*cur1 = *root1; *cur1 != NULL; *cur = (*cur)->next) {
                        if(strcmp((*cur)->element.class_code, (*cur1)->element.class_code) < 0) {
                            insertBeforeCurrent((*cur)->element, &root1, &cur1, &prev1);
                        }
                        else {
                            insertAfterCurrent((*cur)->element, &root1, &cur1, &prev1);
                        }
                    }
                    *cur = (*cur)->next;
                }
            }
            break;
            case 6: {
                FILE *fptr = fopen("Courseinfo.txt", "w");
                if(fptr == NULL) {
                    printf("cannot open file\n");
                    return;
                }
                
            }
        }
    }while(opt != 7);
    return 0;
}