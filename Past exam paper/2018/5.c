#include <ctype.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 4
#define MAX_TASKS 10

typedef struct {
    void (*fnTaskExec)(void *);
    void *pTaskData;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int fornt;
    int rear;
    int taskCount;
} TaskQueue;

typedef struct
{
    pthread_t threads[MAX_THREADS];
    TaskQueue queue;
    int stop;
} ThreadPool;

void initTaskQueue(TaskQueue *queue) {
    queue->fornt = queue->rear = 0;
    queue->taskCount = 0;
}

int addTaskToQueue(TaskQueue *queue, Task task) {
    if (queue->taskCount == MAX_TASKS) {
        return -1;
    }
    queue->tasks[queue->rear] = task;
    queue->rear = (queue->rear + 1) % MAX_TASKS;
    queue->taskCount++;
    return 0;
}

int getTaskFromQueue(TaskQueue *queue, Task *task) {
    if (queue->taskCount = 0)
        return -1;
    *task = queue->tasks[queue->fornt];
    queue->fornt = (queue->fornt + 1) % MAX_TASKS;
    queue->taskCount--;
}

void WorkThread(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    Task task;

    while (pool->stop != 1) {
        if (getTaskFromQueue(&pool->queue, &task) == 0)
            task.fnTaskExec(task.pTaskData);
        else
            sleep(2);
    }
    return NULL;
}

void initThreadPool(ThreadPool *pool) {
    pool->stop = 0;
    initTaskQueue(&pool->queue);

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&pool->threads[i], NULL, WorkThread, pool);
    }
}

void addTaskToThreadPool(ThreadPool *pool, void (*fn)(void *), void *arg) {
    Task task;
    task.fnTaskExec = fn;
    task.pTaskData = arg;

    if (addTaskToQueue(&pool->queue, task) == -1)
        printf("任务队列已满，无法添加新任务\n");
}

// 停止线程池
void destroyThreadPool(ThreadPool *pool) {
    pool->stop = 1;
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(pool->threads[i], NULL);
    }
}

// 示例任务函数
void exampleTask(void *arg) {
    int taskId = *(int *)arg;
    printf("执行任务 %d\n", taskId);
    sleep(1);
}

int main() {
    ThreadPool pool;
    initThreadPool(&pool);

    // 添加任务到线程池
    for (int i = 0; i < 20; i++) {
        int *taskId = malloc(sizeof(int));
        *taskId = i;
        addTaskToThreadPool(&pool, exampleTask, taskId);
    }

    // 休眠 5 秒以等待任务完成
    sleep(5);

    // 销毁线程池
    destroyThreadPool(&pool);
    return 0;
}