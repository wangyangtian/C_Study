#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Point {
    double lon;
    double lat;
    int Movespeed;
    char t[20];
    struct Point* next;
} Point;

typedef struct Typhoon {
    int ID;
    char name[100];
    Point* points;
} Typhoon;

// 初始化台风
void initTyphoon(Typhoon* typhoon) {
    typhoon->ID = 0;
    typhoon->name[0] = '\0';
    typhoon->points = (Point*)malloc(sizeof(Point));
    typhoon->points->next = NULL;
}

// 从文件中读取台风数据
int loadTyphoonData(const char* filename, Typhoon* typhoon) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return 0;
    }

    char line[200];
    initTyphoon(typhoon);

    // 读取 ID 和名称
    if (fscanf(file, "ID:%d\n", &typhoon->ID) != 1) {
        fclose(file);
        fprintf(stderr, "Error reading ID\n");
        return 0;
    }
    if (fscanf(file, "Name:%99s\n", typhoon->name) != 1) {
        fclose(file);
        fprintf(stderr, "Error reading Name\n");
        return 0;
    }

    // 跳过 Points 的前导部分
    fgets(line, sizeof(line), file);  // 跳过 "Points{"

    // 读取文件并创建链表
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '{') {
            Point* newPoint = (Point*)malloc(sizeof(Point));

            // 读取经度
            fscanf(file, "Lon:%lf\n", &newPoint->lon);

            // 读取纬度
            fscanf(file, "Lat:%lf\n", &newPoint->lat);

            // 读取移动速度
            fscanf(file, "Movespeed:%d\n", &newPoint->Movespeed);

            // 读取时间
            fscanf(file, "Time:%s\n", newPoint->t);

            // 初始化next为NULL
            newPoint->next = typhoon->points->next;

            // 将新点插入链表
            typhoon->points->next = newPoint;
        }
    }

    fclose(file);
    return 1;
}

// 打印台风数据
void printTyphoonData(const Typhoon* typhoon) {
    printf("ID: %d\n", typhoon->ID);
    printf("Name: %s\n", typhoon->name);

    Point* current = typhoon->points->next;
    int index = 1;
    while (current != NULL) {
        printf("Point %d: Lon: %.1lf, Lat: %.1lf, Movespeed: %2d, Time: %s\n", index++, current->lon, current->lat, current->Movespeed, current->t);
        current = current->next;
    }
}

// 释放链表内存
void freePoints(Point* head) {
    Point* current = head;
    while (current != NULL) {
        Point* temp = current;
        current = current->next;
        free(temp);
    }
}

void freeTyphoon(Typhoon* typhoon) {
    freePoints(typhoon->points);
    typhoon->points = NULL;
}

// 主函数
int main() {
    Typhoon typhoon;
    if (loadTyphoonData("typhoon.txt", &typhoon)) {
        printTyphoonData(&typhoon);
    }
    Point* newPointSet = (Point*)malloc(sizeof(Point));
    newPointSet->next = NULL;
    int count = 0;

    Point* current = typhoon.points->next;
    while (current != NULL) {
        if (strcmp(current->t, "2023-7-22 00:00:00") > 0 && strcmp(current->t, "2023-7-29 23:00:00") < 0) {
            Point* newPoint = (Point*)malloc(sizeof(Point));
            newPoint->lon = current->lon;
            newPoint->lat = current->lat;
            newPoint->Movespeed = current->Movespeed;
            strcpy(newPoint->t, current->t);
            newPoint->next = newPointSet->next;
            newPointSet->next = newPoint;
            count++;
        }
        current = current->next;
    }
    double Speed = 0;
    current = newPointSet->next;
    for (int i = 0; i < count; i++) {
        Speed += current->Movespeed;
        current = current->next;
    }
    double AvgSpeed = Speed / count;

    printf("共有%d个点，平均速度为 %.1lf\n", count, AvgSpeed);
    // 释放内存
    freeTyphoon(&typhoon);
    return 0;
}
