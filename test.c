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
    int                ID;
    int                PointNum;
    Point*             points;
    struct RodSegment* next;
} RodSegment;

int main() {
    RodSegment* head = NULL;
    RodSegment* tail = NULL;
    int         id, n;

    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("无法打开文件");
        return EXIT_FAILURE;
    }

    while (fscanf(fp, "%d,%d", &id, &n) == 2) { // 确保成功读取两个值
        RodSegment* newRoad = (RodSegment*) malloc(sizeof(RodSegment));
        newRoad->ID         = id;
        newRoad->PointNum   = n;                                  // 保存点的数量
        newRoad->points     = (Point*) malloc(sizeof(Point) * n); // 为 n 个点分配内存
        newRoad->next       = NULL;

        for (int i = 0; i < n; i++) {
            fscanf(fp, "%lf,%lf", &newRoad->points[i].x, &newRoad->points[i].y); // 使用&符号
        }

        if (head == NULL) {
            head = newRoad; // 第一个节点
            tail = newRoad;
        } else {
            tail->next = newRoad; // 将新节点链接到链表
            tail       = newRoad; // 更新尾指针
        }
    }

    fclose(fp); // 关闭文件

    // 输出ID为2的坐标
    RodSegment* current = head;
    while (current != NULL) {
        if (current->ID == 2) {
            printf("ID为%d的坐标如下：\n", current->ID);
            for (int i = 0; i < current->PointNum; i++) {
                printf("(%lf, %lf)\n", current->points[i].x, current->points[i].y);
            }
        }
        current = current->next;
    }

    // 释放内存
    current = head;
    while (current != NULL) {
        RodSegment* temp = current;
        current          = current->next;
        free(temp->points); // 释放点的内存
        free(temp);         // 释放段的内存
    }

    return 0;
}
