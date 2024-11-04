#include <stdio.h>

typedef struct _Point {
    double x;
    double y;
} Point;

void findMonotonicChains(Point points[], int n) {
    if (n < 2) {
        printf("点数不够。\n");
        return;
    }

    int index = 0;
    char direction = points[1].y > points[0].y ? 'I' : 'D';
    for (int i = 0; i < n - 1; i++) {
        char current_direction = points[i].y > points[i + 1].y ? 'I' : 'D';

        if (current_direction != direction) {
            printf("%d-%d(%c)\n", index, i, direction);
            direction = current_direction;
            index = i;
        }
    }
}

int main() {
    Point points[] = {{0, 1}, {1, 3}, {2, 2}, {3, 5}, {4, 6}, {5, 4}};
    int n = sizeof(points) / sizeof(points[0]);

    findMonotonicChains(points, n);

    return 0;
}
