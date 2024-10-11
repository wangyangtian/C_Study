#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(int a[], int low, int high) {
    int pivot = a[low];  // 选择最左边的元素作为基准

    while (low < high) {
        // 从右向左找到第一个小于 pivot 的元素
        while (low < high && a[high] >= pivot)
            --high;
        a[low] = a[high];   // 将找到的小于 pivot 的元素移到左边

        // 从左向右找到第一个大于 pivot 的元素
        while (low < high && a[low] <= pivot)
            ++low;
        a[high] = a[low];  // 将找到的大于 pivot 的元素移到右边
    }

    // 将 pivot 放到最终位置，使得左边都小于等于 pivot，右边都大于等于 pivot
    a[low] = pivot;
    return low;  // 返回 pivot 的最终位置
}

// 递归实现快速排序
void quickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);     // 获取分区点
        quickSortRecursive(arr, low, pi - 1);   // 对左子数组排序
        quickSortRecursive(arr, pi + 1, high);  // 对右子数组排序
    }
}

// 快速排序
void quick_sort(int s[], int left, int right) {
    if (left < right) {
        int i = left, j = right, pivot = s[left];
        while (i < j) {
            while (i < j && s[j] >= pivot)  // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i++] = s[j];

            while (i < j && s[i] < pivot)  // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = pivot;
        quick_sort(s, left, i - 1);  // 递归调用
        quick_sort(s, i + 1, right);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    quickSortRecursive(arr, 0, len - 1);

    printf("排序后的数组: ");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
    return 0;
}