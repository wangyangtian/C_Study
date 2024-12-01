#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    char data;
    struct Tree *lchild, *rchild;
} TNode, *Tree;

Tree creatTree(char pre[], char in[], int n) {
    Tree t = (TNode *)malloc(sizeof(TNode));
    t->data = pre[0];
    t->lchild = t->rchild = NULL;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (in[i] == t->data) {
            index = i;
            break;
        }
    }
    t->lchild = creatTree(pre + 1, in, index);
    t->rchild = creatTree(pre + 1 + index, in + 1 + index, n - index - 1);
}

int main() {
    return 0;
}

/*
数学归纳法:
假设一颗二叉树结点个数为n；前序遍历序列为p1,p2,...,pn;中序遍历序列为i1,i2,...,in;

当n=1 时显然能确定一颗唯一的二叉树；

现在假设n<=m-1时命题成立；

当n=m时，前序序列为p1,p2,...,pm;中序遍历序列为i1,i2,...,im;
其中p1一定为根节点；在中序序列中必能找到ik=p1,k∈[1,m]
k=1时，二叉树的左子树为空，右子树的前序序列为p2,p3,...,pm;中序序列为i2,i3,...im;
节点数为m-1,由假设可知这两个序列可以唯一确定该二叉树的右子树，因此可以唯一确定该二叉树；
同理k=m时，可以唯一确定该二叉树的左子树，因此可以确定该二叉树；

1<k<m时，可以得到该二叉树的左子树的前序序列为p2,...,p(k-2);中序序列i1,i2,...,i(k-1);
节点数<m-1,故可以唯一确定左子树tl；同理可以确定右子树tr；由二叉树的性质可以唯一确定该二叉树为tl-p1-tr；

*/