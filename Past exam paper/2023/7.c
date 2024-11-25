#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point {
    float x;
    float y;
    struct point* next;
} Point;

typedef struct ploy {
    char type[20];
    int Num;
    Point* Points;
    struct ploy* next;
} ploy;

typedef struct Ring {
    ploy Exterior;
    ploy Interior;
} Ring;

void load(const char* path, Ring* i) {
    FILE* fp = fopen(path, "r");
    char str1[10], str2[10];
    while (fscanf(fp, "%s %s", str1, str2) == 2) {
        ploy* whichPloy;
        if (strcmp(str1, "#Exterior") == 0) {
            strcpy(i->Exterior.type, "Exterior Ring");
            whichPloy = &i->Exterior;
        } else {
            strcpy(i->Interior.type, "Interior Ring");
            whichPloy = &i->Interior;
        }

        fscanf(fp, "%d", &whichPloy->Num);

        whichPloy->Points = (Point*)malloc(sizeof(Point));
        whichPloy->Points->next = NULL;
        Point* p = whichPloy->Points;

        for (int j = 0; j < whichPloy->Num; j++) {
            Point* pt = (Point*)malloc(sizeof(Point));
            fscanf(fp, "%f, %f", &pt->x, &pt->y);
            pt->next = NULL;
            p->next = pt;
            p = pt;
        }
    }
    fclose(fp);
}

void print(Ring* i, char type) {
    ploy* t;
    if (type == 'e')
        t = &i->Exterior;
    else
        t = &i->Interior;

    // 输出结果验证
    printf("Exterior Type: %s\n", t->type);
    printf("Exterior Points:\n");
    Point* p = t->Points->next;
    while (p != NULL) {
        printf("(%.3f, %.3f)\n", p->x, p->y);
        p = p->next;
    }
}

void delete(Ring* i, char type, int n) {
    ploy* t;
    if (type == 'e')
        t = &i->Exterior;
    else
        t = &i->Interior;

    Point* prev = t->Points;
    for (int i = 0; i < n - 1; i++)
        prev = prev->next;
    Point* current = prev->next;
    prev->next = current->next;
    free(current);
}

void insert(Ring* i, char type, int n, Point pt) {
    ploy* t;
    if (type == 'e')
        t = &i->Exterior;
    else
        t = &i->Interior;
    Point* prev = t->Points;
    for (int i = 0; i < n - 1; i++)
        prev = prev->next;
    Point* current = prev->next;
    Point* add = (Point*)malloc(sizeof(Point));
    add->x = pt.x;
    add->y = pt.y;
    add->next = current;
    prev->next = add;
}

int main() {
    Ring i;
    load("data.txt", &i);
    delete (&i, 'e', 4);
    Point p = {1, 5, NULL};
    insert(&i, 'e', 2, p);
    print(&i, 'e');

    return 0;
}