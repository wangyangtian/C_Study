#include <stdio.h>

int quick_select(int s[], int left, int right, int k) {
    if (left <= right) {
        int i = left, j = right, pivot = s[left];
        while (i < j) {
            while (i < j && s[j] <= pivot)  // 从右向左找第一个大于 pivot 的数
                j--;
            if (i < j)
                s[i++] = s[j];
            // 从左向右找第一个小于等于 pivot 的数
            while (i < j && s[i] > pivot)
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = pivot;

        // i 是当前 pivot 的最终位置，检查它是否是第 k 大元素
        if (i == k - 1)  // 找到第 k 大元素
            return s[i];
        else if (i > k - 1)  // 递归到左半部分
            return quick_select(s, left, i - 1, k);
        else  // 递归到右半部分
            return quick_select(s, i + 1, right, k);
    }
    return -1;  // 当 k 超出数组范围时
}

void Sort(int* a, int left, int right) {
    for (int i = left; i < right; i++) {
        for (int j = left; j < right - i + left; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int result = quick_select(arr, 0, n - 1, k);
    if (result != -1) {
        printf("数组中第 %d 大的元素是 %d\n", k, result);
    } else {
        printf("k 超出数组范围\n");
    }
    Sort(arr, 0, 3);
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
