#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 20; j++) {
            for (int k = 1; k < 200; k++) {
                if (10 * i + 5 * j + k * 0.5 == 100)
                    printf("10元%d张,5元%d张,0.5元%d张\n", i, j, k);
            }
        }
    }
}

int main() {
    fun();
    return 0;
}