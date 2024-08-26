#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXVERTEXNUM 100
#define INFINITY INT_MAX

typedef struct MGraph//邻接矩阵
{
    char Vex[MAXVERTEXNUM]; //顶点表
    int Edge[MAXVERTEXNUM][MAXVERTEXNUM];//邻接矩阵，边表
    int vexnum,arcnum;  //当前顶点数和弧数
}MGraph;

//邻接表
typedef struct ArcNode{     //边
    int adjvex;             //弧指向的结点
    struct ArcNode *next;   //指向下一条弧的指针
    //int Info;             //边权值   
}ArcNode;

typedef struct VNode{   //顶点
    char data;          //顶点信息   
    ArcNode *first;     //指向第一条弧的指针
}VNode,AdjList[MAXVERTEXNUM];

typedef struct ALGraph
{
    AdjList vertices;
    int vexnum,arcnum;
};

typedef struct LinkQueue
{
    int data;
    struct LinkQueue *next;
}LinkNode;
typedef struct  // 链队类型定义
{
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue *q){//初始化队列
    q->front=q->rear=(LinkNode*)malloc(sizeof(LinkNode));
    q->front->next=NULL;
}

void EnQueue(LinkQueue *q,int elem){    //带头结点的入队
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data=elem;
    s->next=NULL;
    q->rear->next=s;
    q->rear=s;
}

bool DeQueue(LinkQueue *q,int* elem){   // 带头结点的出队
    if(q->front==q->rear)
        return false;
    LinkNode *p=q->front->next;
    *elem=p->data;
    q->front->next=p->next;
    if(q->rear==p)      // 最后一次出队，修改rear指针
        q->rear=q->front;
    free(p);
}

void visit(int v){
}


//广度优先遍历
void BFS(MGraph g,int v){   //从顶点v出发，广度优先遍历图G
    bool Visited[MAXVERTEXNUM]=false;
    visit(v);
    Visited[v]=true;
    

}

int main() {
    
    return 0;
}