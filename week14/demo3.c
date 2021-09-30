#include<stdio.h>
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

int bunsearch(int list[], int searchnum, int n) {
    int left = 0, right = n-1, middle;
    while(left <= right) {
        middle = (left+right)/2;
        if(list[middle] < searchnum) left = middle+1;
        else if(list[middle] == searchnum) return middle;
        else right = middle-1;
    }
    return -1;
}
void verify(int list1[], int list2[], int n, int m) {
    mergeSort(list1, 0, n-1);
    mergeSort(list2, 0, m-1);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(list1[i] < list2[j]) {
            printf("%d is not in list 2\n", list1[i]);
            i++;
        }
        else if(list1[i] == list2[j]) {
            i++;
            j++;
        }
        else {
            printf("%d is not in list 1\n", list2[j]);
            j++;
        }
    }
    for(; i < n; i++) printf("%d is not in list 2\n", list1[i]);
    for(; j < m; j++) printf("%d is not in list 1\n", list2[j]);
}
int main() {
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 3, 5, 7, 9};
    verify(a, b, 5, 5);
    return 0;
}