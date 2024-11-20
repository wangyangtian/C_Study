#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int stack[N];
int top = -1;

void bSearch(int a[], int low, int high, int target) {
    if (low <= high) {
        int mid = (low + high) / 2;
        stack[++top] = mid;
        if (a[mid] == target)
            return;
        else if (a[mid] < target)
            bSearch(a, mid + 1, high, target);
        else
            bSearch(a, low, mid - 1, target);
    }
}

int main() {
    int a[] = {1, 22, 33, 44, 55, 66, 77, 88, 99, 100};
    int target = 55;
    bSearch(a, 0, 9, target);
    printf("%d对应的下标为%d", target, stack[top]);
    return 0;
}