#include<stdio.h>
#include<time.h>
#define MAX 20000
typedef int Type;
typedef struct element{
    Type key;
}element;

void insertion_sort(element list[], int n) {
    int i, j;
    element next;
    for(i = 1; i < n; i++) {
        next = list[i];
        for(j = i-1; j >= 0 && next.key < list[j].key; j--) {
            list[j+1] = list[j];
        }
        list[j+1] = next;
    }
}

void selection(element a[], int n) {
    int i, j, min;
    element tmp;
    for(i = 0; i < n-1; i++) {
        min = i;
        for(j = i+1; j <= n-1; j++) {
            if(a[j].key < a[min].key) min = j;
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
}

void adjust(element list[], int root, int n) {
    int child, rootkey;
    element temp;
    temp = list[root];
    rootkey = list[root].key;
    child = 2 * root;
    while(child <= n) {
        if((child < n) && (list[child].key < list[child+1].key)) child++;
        if(rootkey > list[child].key) break;
        else {
            list[child/2] = list[child];
            child *= 2;
        }
    }
    list[child/2] = temp;
}
void heapsort(element list[], int n) {
    int i, j;
    element temp;
    for(i = n/2; i > 0; i--) adjust(list, i , n);
    for(i = n-1; i > 0; i--) {
        temp = list[1];
        list[1] = list[i+1];
        list[i+1] = temp;
        adjust(list, 1, i);
    }
}

void quicksort(element list[], int left, int right) {
    int pivot, i, j;
    element temp;
    if(left < right) {
        i = left;
        j = right+1;
        pivot = list[left].key;
        do {
            do i++;
            while(list[i].key < pivot);
            do j--;
            while(list[j].key > pivot);
            if(i < j) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }while(i < j);
        temp = list[left];
        list[left] = list[j];
        list[j] = temp;
        quicksort(list, left, j-1);
        quicksort(list, j+1, right);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
int main() {
    int a[MAX];
    srand((int)time(0));
    int i;
    for(i = 0; i < MAX; i++) {
        a[i] = rand();
    }
    clock_t start, end;
    start = clock();
    insertion_sort(a, MAX);
    end = clock();
    printf("Time is %f s\n", (double)(end - start)/CLOCKS_PER_SEC);
    //selection(a, 5);
    start = clock();
    //heapsort(a, MAX);
    quicksort(a, 0, MAX-1);
    end = clock();
    printf("Time is %f s\n", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}