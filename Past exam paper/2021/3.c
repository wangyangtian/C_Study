#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxSubArray(int nums[], int N) {
    int max = INT_MIN;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += nums[j];
            max = max > sum ? max : sum;
        }
    }
    return max;
}

int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    printf("%d", maxSubArray(a, 9));
    return 0;
}