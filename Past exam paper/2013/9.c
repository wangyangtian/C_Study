#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Course {
    int c_id;
    char c_name[255];
    double score;
} Course;

typedef struct _Student {
    int stu_id;
    char stu_name[255];
    Course course[100];
    int c_num;
} Student;

typedef struct _Class {
    int class_id;
    int stu_num;
    Student stu[100];
} Class;

typedef struct _System {
    int class_num;
    Class class[100];
} System;

void creatClass(Class* new_class) {
    scanf("%d", &new_class->class_id);
    scanf("%d", &new_class->stu_num);

    for (int i = 0; i < new_class->stu_num; i++) {
        scanf("%d", &new_class->stu[i].stu_id);
        scanf("%s", new_class->stu[i].stu_name);
        scanf("%d", &new_class->stu[i].c_num);

        for (int j = 0; j < new_class->stu[i].c_num; j++) {
            scanf("%d", &new_class->stu[i].course[j].c_id);
            scanf("%s", new_class->stu[i].course[j].c_name);
            scnaf("%d", &new_class->stu[i].course[j].score);
        }
    }
}

void addStudent(Class* cla) {
    scanf("%d", &cla->stu[cla->stu_num].stu_id);
    scanf("%s", cla->stu[cla->stu_num].stu_name);
    scanf("%d", &cla->stu[cla->stu_num].c_num);

    for (int i; i < cla->stu[cla->stu_num].c_num; i++) {
        scanf("%d", &cla->stu[cla->stu_num].course[i].c_id);
        scanf("%s", cla->stu[cla->stu_num].course[i].c_name);
        scanf("%d", &cla->stu[cla->stu_num].course[i].score);
    }

    cla->stu_num++;
}

void deleteStudent(Class* cla, int student_id) {
    int i;

    for (i = 0; i < cla->stu_num; i++) {
        if (cla->stu[i].stu_id == student_id) {
            break;
        }
    }

    for (int j = i; j < cla->stu_num - 1; j++) {
        cla->stu[j] = cla->stu[j + 1];
    }

    cla->stu_num--;
}

void addCourse(Class* cla, Course new_course) {
    for (int i = 0; i < cla->stu_num; i++) {
        cla->stu[i].course[cla->stu[i].c_num] = new_course;
        cla->stu[i].c_num++;
    }
}

void alterScore(Class* cla, int stu_id, int c_id, int score) {
    for (int i = 0; i < cla->stu_num; i++) {
        if (cla->stu[i].stu_id == stu_id) {
            for (int j = 0; j < cla->stu[i].c_num; i++) {
                if (cla->stu[i].course[j].c_id == c_id) {
                    cla->stu[i].course[j].score = score;
                    break;
                }
            }
        }
    }
}

int main() {
    frand(time(NULL));
    return 0;
}