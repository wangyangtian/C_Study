#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[] = "10------------------------#共有 10 个多边形";
    int n;
    sscanf(a, "%d", &n);
    printf("%d", n);
    return 0;
}