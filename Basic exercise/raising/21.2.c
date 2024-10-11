#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LowerBound(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    int pos = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid]>=target)
            right = mid - 1;
        else{
            pos = mid;
            left = mid + 1;
        }   
    }
    return pos;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int pos = LowerBound(a, 10, 8);
    printf("%d",pos);
    return 0;
}