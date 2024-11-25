#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p {
    double x;
    double y;
} Point;

typedef struct RodSegment {
    int ID;
    int PointNum;
    Point* points;
    struct RodSegment* next;
} RodSegment;

int main() {
    RodSegment* head = (RodSegment*)malloc(sizeof(RodSegment));
    head->next = NULL;
    RodSegment* r = head;
    int id, n;

    FILE* fp = fopen("road.txt", "r");
    if (fp == NULL) {
        perror("无法打开文件");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%d, %d", &id, &n) == 2) {
        RodSegment* newRoad = (RodSegment*)malloc(sizeof(RodSegment));
        newRoad->ID = id;
        newRoad->PointNum = n;
        newRoad->points = (Point*)malloc(sizeof(Point) * n);
        newRoad->next = NULL;

        for (int i = 0; i < n; i++) {
            fscanf(fp, "%lf, %lf", &newRoad->points[i].x, &newRoad->points[i].y);
        }
        r->next = newRoad;
        r = newRoad;
    }

    fclose(fp);

    RodSegment* current = head->next;  // 从头节点的下一个节点开始遍历
    while (current != NULL) {
        if (current->ID == 2) {
            printf("ID为%d的坐标如下：\n", current->ID);
            for (int i = 0; i < current->PointNum; i++) {
                printf("(%lf, %lf)\n", current->points[i].x, current->points[i].y);
            }
            break;
        }
        current = current->next;
    }

    return 0;
}