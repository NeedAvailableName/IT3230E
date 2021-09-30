typedef struct diemthi_t{
    char name[40];
    float toan;
    float van;
    float anh;
}diemthi;
typedef diemthi elementType;
#include"SLL.h"

int main() {
    int i = 0;
    singlelist root = NULL;
    singlelist cur = NULL;
    singlelist prev = NULL;
    //singlelist root1 = NULL;
    //singlelist cur1 = NULL;
    //singlelist prev1 = NULL;
    FILE *fptr = fopen("diemthi.txt", "r");
    if(fptr == NULL) printf("cannot open file\n");
    elementType *s = (elementType *)malloc(sizeof(elementType));
    while(fread(s, sizeof(elementType), 1, fptr) != 0) {
        insertAtHead(*s, &root, &cur, &prev);
    }
    free(s);
    /*for(cur = root; cur != NULL; cur = cur->next) {
        if(cur->element.toan >= 7.75) insertAfterCurrent(cur->element, &root1, &cur1, &prev1);
    }
    singlelist temp;
    for(cur1 = root1; cur1 != NULL; cur1 = cur1->next) {
        for(temp = cur1->next; temp != NULL; temp = temp->next) {
            if(cur1->element.anh < temp->element.anh) {
                elementType tmp = cur1->element;
                cur1->element = temp->element;
                temp->element = tmp;
            }
        }
    }*/
    for(cur = root; cur != NULL; cur = cur->next) {
        printf("%d %-20s %.2f %.2f %.2f\n", i+1, cur->element.name, cur->element.toan, cur->element.van, cur->element.anh);
        i++;
    }
    fclose(fptr);
    return 0;
}
