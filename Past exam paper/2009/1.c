#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    for (int i = 1; i <= 200; i++) {
        int sum = 0;
        int t = i;
        while (t > 0) {
            int j = t % 10;
            sum += j * j * j;
            t = t / 10;
        }
        if (sum == i) {
            printf("%d ", i);
        }
    }
    return 0;
}