#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

void quickSort(int a[], int left, int right) {
    if (left < right) {
        int i = left, j = right;
        int pivot = a[left];

        while (i < j) {
            while (i < j && a[j] >= pivot)
                j--;
            if (i < j)
                a[i++] = a[j];

            while (i < j && a[i] <= pivot)
                i++;
            if (i < j)
                a[j--] = a[i];
        }

        a[i] = pivot;
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
}

int main() {
    
    return 0;
}