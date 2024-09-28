#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, *LinkList;

bool IsSubset(LinkList a, LinkList b) {
    LNode* pa = a->next;
    while (pa != NULL) {
        LNode* pb = b->next;  // 每次遍历 b 都从头开始
        bool exist = false;    // 重置 exist 状态
        while (pb != NULL) {
            if (pb->data == pa->data) {  // 如果找到匹配
                exist = true;
                break;  // 找到后可以退出当前内层循环
            }
            pb = pb->next;
        }
        if (!exist) {  // 如果当前 pa->data 在 b 中找不到匹配，返回 false
            return false;
        }
        pa = pa->next;  // 继续下一个元素
    }
    return true;  // 如果所有 pa->data 都在 b 中找到匹配，返回 true
}


int main() {
    return 0;
}