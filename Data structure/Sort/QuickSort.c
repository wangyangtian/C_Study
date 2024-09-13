#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int a[], int low, int high) {
    int pivot=a[low];
    while (low<high){
        while(low<high&&a[high]>=pivot) --high;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)  ++low;
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
    
}

// 递归实现快速排序
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 获取分区点
        quickSortRecursive(arr, low, pi - 1); // 对左子数组排序
        quickSortRecursive(arr, pi + 1, high); // 对右子数组排序
    }
}

int main() {
    return 0;
}