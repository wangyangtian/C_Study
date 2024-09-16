#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Merge(int a[], int low, int mid, int high) {
    int* b = (int*)malloc(sizeof(int) * (high - low + 1));
    for (int k = low; k <= high; k++) {
        b[k] = a[k];
    }

    int i = low, j = mid + 1;
    int k = low;
    while (i <= mid && j <= high) {
        if (b[i] <= b[j])
            a[k++] = b[i++];
        else
            a[k++] = b[j++];
    }
    while (i <= mid)
        a[k++] = b[i++];
    while (j <= high)
        a[k++] = b[j++];
}
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
    for (int i = 5; i >=0; i--) {
        printf("%d ", a[i]);
    }
    return 0;
}