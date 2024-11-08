#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trail(int matrix[3][3]) {
    int trail = 0;
    for (int i = 0; i < 3; i++) {
        trail += matrix[i][i];
    }
    return trail;
}

int main() {
    return 0;
}