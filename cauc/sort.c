#include <stdio.h>
#define N 1000
int arr[N];

/* 对长度为n的数组arr执行冒泡排序 */
void bubbleSort(int arr[], int n);

/* 打印长度为n的数组arr */
void printArray(int arr[], int n);

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
/* 打印长度为n的数组arr */
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)    /* 下标0..n-2每个元素后面有个空格 */
            printf(" ");   /*下标n-1,也就是最后一个元素后面没有空格*/
    }
    printf("\n");  /* 一行打印完后换行 */
}

/* 你的代码将嵌在这里 */
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] < arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}