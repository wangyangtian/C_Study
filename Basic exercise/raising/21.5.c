#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isBadVersion(int version) {}

int firstBadVersion(int version) {
    int left = 1, right = version;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isBadVersion(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}

int main() {
    return 0;
}