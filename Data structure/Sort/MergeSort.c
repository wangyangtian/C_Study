#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将两个已排序的子数组合并成一个有序的数组
void Merge(int a[], int low, int mid, int high) {
    int* b = (int*)malloc(sizeof(int) * (high - low + 1));
    for (int k = low; k <= high; k++) {
        b[k] = a[k];
    }

    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (b[i] < b[j])
            a[k++] = b[i++];
        else
            a[k++] = b[j++];
    }
    
    while (i <= mid) 
        a[k++] = b[i++];
    while (j <= high) 
        a[k++] = b[j++];
}
// 递归地将数组分成两个子数组，直到子数组长度为 1，然后调用 merge 函数合并排序。
void MergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

int main() {
    int a[] = {4, 6, 7, 2, 1, 8};
    MergeSort(a, 0, 5);
    for (int i = 0; i < 6; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}