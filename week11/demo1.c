#include<stdio.h>
#include<time.h>
#define MAX 1000000
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

int BinarySearch(int A[], int X, int Low, int High) {
    if(Low > High) return -1;
    int Mid = (Low + High) / 2;
    if(A[Mid] < X) return BinarySearch(A, X, Mid+1, High);
    else if(A[Mid] > X) return BinarySearch(A, X, Low, Mid-1);
    else return Mid;
}

int main() {
    clock_t start, end, total;
    int a[MAX];
    int i;
    for(i = 0; i < MAX; i++) {
        a[i] = 2*i;
    }
    start = clock();
    printf("%d\n", binarySearch(a, 1543248, MAX));
    end = clock();
    printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    printf("%d\n", BinarySearch(a, 1543248, 0, MAX-1));
    end = clock();
    printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}