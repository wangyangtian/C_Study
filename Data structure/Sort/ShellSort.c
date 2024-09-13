#include <stdio.h>

// 希尔排序函数
void shell_sort(int arr[], int len) {
    int gap, i, j;  // gap是增量，i和j是用于遍历数组的索引
    int temp;       // 用于暂存当前待比较的元素

    // 逐步缩小增量，初始增量为数组长度的一半
    for (gap = len >> 1; gap > 0; gap >>= 1) {
        // 从增量位置开始，对每个元素进行插入排序
        for (i = gap; i < len; i++) {
            temp = arr[i];  // 暂存当前元素

            // 对距离gap的元素进行插入排序
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j + gap] = arr[j];  // 将元素向后移动
            }

            // 插入当前元素到正确位置
            arr[j + gap] = temp;
        }
    }
}

// 打印数组的函数
void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {37, 23, 0, 17, -5, 29, 15}; // 测试数组
    int len = sizeof(arr) / sizeof(arr[0]);  // 计算数组长度

    printf("排序前的数组: ");
    printArray(arr, len); // 输出排序前的数组

    shell_sort(arr, len); // 调用希尔排序函数

    printf("排序后的数组: ");
    printArray(arr, len); // 输出排序后的数组

    return 0;
}
