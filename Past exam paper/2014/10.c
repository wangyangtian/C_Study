#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Geo {
    char type[10];

    union {
        struct _Line {
            double x0, y0;
            double x1, y1;
        } Line;

        struct _Rect {
            double x, y;
            double width, height;
        } Rect;

        struct _Circle {
            double x, y;
            double r;
        } Circle;
    } attr;
} Geo;

typedef struct Node {
    Geo data;
    struct Node* next;
} Node, *List;

int checkAttr(char* str) {
    if (strncmp("LINE", str, 4) == 0)
        return 1;
    if (strncmp("RECT", str, 4) == 0)
        return 2;
    if (strncmp("CIRCLE", str, 6) == 0)
        return 3;
    if (strncmp("END", str, 3) == 0)
        return -1;
    return 0;  // 若未匹配任何几何类型
}

void readFile(char* filePath, List l) {
    FILE* fp = fopen(filePath, "r");
    if (!fp) {
        perror("无法打开文件");
        return;
    }

    char buffer[1024];
    List tail = l;  // 追踪链表末尾
    while (fgets(buffer, sizeof(buffer), fp) && checkAttr(buffer) != -1) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            perror("内存分配失败");
            fclose(fp);
            return;
        }

        switch (checkAttr(buffer)) {
            case 1:
                strcpy(newNode->data.type, "LINE");
                fgets(buffer, sizeof(buffer), fp);
                sscanf(buffer, "%lf %lf %lf %lf",
                       &newNode->data.attr.Line.x0, &newNode->data.attr.Line.y0,
                       &newNode->data.attr.Line.x1, &newNode->data.attr.Line.y1);
                break;
            case 2:
                strcpy(newNode->data.type, "RECT");
                fgets(buffer, sizeof(buffer), fp);
                sscanf(buffer, "%lf %lf %lf %lf",
                       &newNode->data.attr.Rect.x, &newNode->data.attr.Rect.y,
                       &newNode->data.attr.Rect.width, &newNode->data.attr.Rect.height);
                break;
            case 3:
                strcpy(newNode->data.type, "CIRCLE");
                fgets(buffer, sizeof(buffer), fp);
                sscanf(buffer, "%lf %lf %lf",
                       &newNode->data.attr.Circle.x, &newNode->data.attr.Circle.y,
                       &newNode->data.attr.Circle.r);
                break;
            default:
                free(newNode);
                continue;
        }
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    fclose(fp);
}

void printGraph(List l, int sign) {
    l = l->next;  // 跳过头节点
    while (l != NULL) {
        if ((sign == 1 && strcmp(l->data.type, "LINE") == 0) ||
            (sign == 2 && strcmp(l->data.type, "RECT") == 0) ||
            (sign == 3 && strcmp(l->data.type, "CIRCLE") == 0)) {
            if (sign == 1) {
                printf("LINE: %.2lf %.2lf %.2lf %.2lf\n",
                       l->data.attr.Line.x0, l->data.attr.Line.y0,
                       l->data.attr.Line.x1, l->data.attr.Line.y1);
            } else if (sign == 2) {
                printf("RECT: %.2lf %.2lf %.2lf %.2lf\n",
                       l->data.attr.Rect.x, l->data.attr.Rect.y,
                       l->data.attr.Rect.width, l->data.attr.Rect.height);
            } else if (sign == 3) {
                printf("CIRCLE: %.2lf %.2lf %.2lf\n",
                       l->data.attr.Circle.x, l->data.attr.Circle.y,
                       l->data.attr.Circle.r);
            }
        }
        l = l->next;
    }
}

void freeAll(List l) {
    Node* current = l;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    List l = (List)malloc(sizeof(Node));
    if (!l) {
        perror("内存分配失败");
        return 1;
    }
    l->next = NULL;

    char filePath[] = "data.txt";
    readFile(filePath, l);

    printf("输出线请输入1，输出矩形请输入2，输出圆请输入3\n");
    int sign;
    scanf("%d", &sign);
    printGraph(l, sign);

    freeAll(l);

    return 0;
}
