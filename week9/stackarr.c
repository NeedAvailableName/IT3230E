#include"stackarr.h"
int main() {
    int a[MAX];
    int i, n;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    StackType stack;
    initialize(stack);
    for(i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &a[i]);
        push(a[i], stack);
    }
    printf("Pop all elements in stack!\n");
    while(!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
    push(6, stack);
    while(!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("Stack top is: %d\n", peek(stack));
    return 0;
}