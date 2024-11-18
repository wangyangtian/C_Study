#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 999;
    for (int i = 0; i <= n; i++) {
        int t = i * i;
        char a[10] = {'\0'};
        sprintf(a, "%d", t);
        int l = 0;
        int r = strlen(a) - 1;
        while (l <= r) {
            if (a[l] == a[r]) {
                l++, r--;
            } else
                break;
        }
        if (l > r) {
            printf("%d ", t);
        }
    }
    return 0;
}