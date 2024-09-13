#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 交换两个整数的值
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 调整堆，使得以start为根的子树满足最大堆的性质
void max_heapify(int a[], int start, int end) {
    int temp = a[start]; // 暂存根节点的值
    // 从start节点开始，调整整个子树
    for (int i = 2 * start + 1; i <= end; i = i * 2 + 1) { // i是左孩子节点
        if (i < end && a[i] < a[i + 1]) // 如果右孩子存在且比左孩子大
            i++; // i指向较大的子节点
        if (a[i] > temp) { // 如果子节点大于根节点
            a[start] = a[i]; // 将子节点的值赋给根节点
            start = i; // 更新根节点的位置为i
        } else {
            break; // 如果子节点不大于根节点，则调整完成
        }
    }
    a[start] = temp; // 将原根节点的值放到正确的位置
}

// 建立最大堆
void BuildMaxHeap(int a[], int len) {
    // 从最后一个非叶节点开始，向上调整堆
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(a, i, len - 1); // 调整以i为根的子树
}

// 堆排序
void HeapSort(int a[], int len) {
    BuildMaxHeap(a, len); // 首先建立最大堆
    // 将堆顶（最大值）与当前堆的最后一个元素交换，然后调整新的堆顶
    for (int i = len - 1; i > 0; i--) {
        swap(&a[0], &a[i]); // 交换堆顶和堆尾
        max_heapify(a, 0, i - 1); // 调整堆，重新保持最大堆性质
    }
}

int main() {
    int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7,
                 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
    int len = (int)sizeof(arr) / sizeof(*arr);
    HeapSort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}