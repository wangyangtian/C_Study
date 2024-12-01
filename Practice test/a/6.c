#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
算法思路：以待排序数组的第一个元素作为枢轴（pivot），
通过一次划分操作将数组分为左侧小于 pivot 的部分和右侧大于 pivot 的部分；
然后递归地对左、右两部分分别调用快速排序函数，最终实现整个数组的排序。
*/

void quickSort(int a[], int left, int right) {
    if (left > right)
        return;

    int pivot = a[left];
    int i = left, j = right;

    while (i < j) {
        while (i < j && a[j] >= pivot) {
            j--;
        }
        if (i < j)
            a[i++] = a[j];
        while (i < j && a[i] <= pivot) {
            i++;
        }
        if (i < j)
            a[j--] = a[i];
    }

    a[i] = pivot;
    quickSort(a, left, i - 1);
    quickSort(a, i + 1, right);
}

int main() {
    int a[] = {6, 5, 1, 8, 2, 7, 9, 3, 4};
    quickSort(a, 0, 8);
    for (int i = 0; i < 9; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}