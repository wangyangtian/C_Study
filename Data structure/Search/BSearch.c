#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 二分查找
int BSearch_R(int a[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] > target)
            return BSearch_R(a, left, mid - 1, target);
        if (a[mid] < target)
            return BSearch_R(a, mid + 1, right, target);
    }
    return -1;
}

int BSearch(int a[], int len, int target) {
    int left = 0, right = len - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == target)
            return mid;
        if (a[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    BSearch_R(a, 1, 18, 15);
    return 0;
}