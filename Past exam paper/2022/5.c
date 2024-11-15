#include <stdio.h>

void fun(char tree[], int n, int i) {
    // 计算父节点的索引
    int parent = (i - 1) / 2;  // 父节点索引修正
    if (i == 0) {
        printf("%c没有双亲节点,", tree[i]);
    } else {
        printf("%c的双亲节点为%c,", tree[i], tree[parent]);
    }

    // 计算左右孩子节点的索引
    int lchild = 2 * i + 1;
    int rchild = 2 * i + 2;

    // 检查左孩子是否存在
    if (lchild < n) {
        printf("左孩子为%c,", tree[lchild]);
    } else {
        printf("没有左孩子,");
    }

    // 检查右孩子是否存在
    if (rchild < n) {
        printf("右孩子为%c\n", tree[rchild]);
    } else {
        printf("没有右孩子\n");
    }
}

int main() {
    char tree[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};  // 完全二叉树
    int n = sizeof(tree) / sizeof(tree[0]);             // 计算节点数量

    for (int i = 0; i < n; i++) {
        fun(tree, n, i);  // 遍历每个节点
    }

    return 0;
}
