#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findKthLargest(int *a, int left, int right, int k) {
    if (left <= right) {
        int pivot = a[left];
        int i = left;
        int j = right;

        while (i < j) {
            while (i < j && a[j] <= pivot)
                j--;
            if (i < j)
                a[i++] = a[j];
            while (i < j && a[i] >= pivot)
                i++;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = pivot;

        if (i == k - 1)
            return a[i];
        if (i < k - 1)
            return findKthLargest(a, i + 1, right, k);
        if (i > k - 1)
            return findKthLargest(a, left, i - 1, k);
    }
    return -1;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", findKthLargest(a, 0, 8, 3));
    return 0;
}