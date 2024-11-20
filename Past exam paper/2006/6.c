#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool BSearch(int a[], int left, int right, int x) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (a[mid] == x)
            return true;
        else if (a[mid] < x) {
            BSearch(a, mid + 1, right, x);
        } else
            BSearch(a, left, mid - 1, x);
    }
}

int main() {
    return 0;
}