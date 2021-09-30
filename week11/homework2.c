/*Write a program that declares an array of at least 200000 integers 
(you can try with 500000 or 1 million integers).
Initialize the array elements with ascending values.
(For example a[i] = 2*i+3)
The program provides a menu for:
- Sequential search
- Sequential search using Sentinel
- Binary search
For each funtionality, display not only the result but the execution time.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500000

int sequential_search(int A[], int key) {
    int i, count = 0;
    for(i = 0; i < MAX; i++) {
        if(key == A[i]) return i;
        count++;
    }
    if(count == 0) return -1;
}

int sentinel_search(int A[], int key) {
    int k = 0;
    A[MAX] = key;
    while(A[k] != key) {
        k++;
    } 
    return k;
}

int binarySearch(int A[], int X, int N) {
    int Low, Mid, High;
    Low = 0;
    High = N - 1;
    while(Low <= High) {
        Mid = (Low + High) / 2;
        if(A[Mid] < X) {
            Low = Mid + 1;
        }
        else if(A[Mid] > X) {
            High = Mid - 1;
        }
        else return Mid;
    }
    return -1;
}

int main() {
    clock_t start, end, total;
    int a[MAX], i, opt, num;
    for(i = 0; i < MAX; i++) {
        a[i] = 2*i;
    }
    printf("Enter the number to search: ");
    scanf("%d", &num);
    do {    
        printf("1. Sequential search\n");
        printf("2. Sequential search using Sentinel\n");
        printf("3. Binary search\n");
        printf("4. Exit\n");
        printf("Enter your option\n");
        scanf("%d", &opt);
        switch(opt) {
            case 1: {
                start = clock();
                printf("Searching result: in position %d\n", sequential_search(a, num));
                end = clock();
                total = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Time is %lf s\n", total);
            }
            break;
            case 2: {
                start = clock();
                printf("Searching result: in position %d\n", sentinel_search(a, num));
                end = clock();
                total = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Time is %lf s\n", total);
            }
            break;
            case 3: {
                start = clock();
                printf("Searching result: in position %d\n", binarySearch(a, num, MAX));
                end = clock();
                total = (double)(end - start) / CLOCKS_PER_SEC;
                printf("Time is %lf s\n", total);
            }
            break;
            case 4: {
                printf("Exit\n");
            }
            break;
            default:
            break;
        }
    }while(opt != 4);
    return 0;
}