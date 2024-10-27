#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WINDOWS 4     // 银行窗口数量
#define MAX_CUSTOMERS 100 // 最大客户数量

typedef struct {
    int arrival_time; // 客户到达时间
    int service_time; // 客户办理业务时间
    int finish_time;  // 客户完成时间
} Customer;

typedef struct {
    Customer *queue[MAX_CUSTOMERS]; // 客户队列
    int front;                      // 队列头
    int rear;                       // 队列尾
    int count;                      // 当前队列中客户数量
} Queue;

// 初始化队列
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

// 入队操作
int enqueue(Queue *q, Customer *customer) {
    if (q->count >= MAX_CUSTOMERS)
        return 0; // 队列已满
    q->queue[q->rear] = customer;
    q->rear = (q->rear + 1) % MAX_CUSTOMERS;
    q->count++;
    return 1; // 入队成功
}

// 出队操作
Customer *dequeue(Queue *q) {
    if (q->count == 0)
        return NULL; // 队列为空
    Customer *customer = q->queue[q->front];
    q->front = (q->front + 1) % MAX_CUSTOMERS;
    q->count--;
    return customer; // 返回出队客户
}

void simulateBank(Queue *windows[], int num_windows) {
    int current_time = 0;    // 当前时间
    int finish_time = 100;   // 银行关门时间
    int total_stay_time = 0; // 客户总逗留时间
    int num_customers = 0;   // 统计实际客户数量

    while (current_time < finish_time) {
        // 随机决定是否有新客户到达
        if (rand() % 2 == 0) { // 每单位时间有50%概率有新客户
            Customer *customer = (Customer *)malloc(sizeof(Customer));
            customer->arrival_time = current_time;
            customer->service_time = rand() % 5 + 1; // 随机生成办理业务时间（1到5）
            customer->finish_time = 0;               // 初始化完成时间

            // 找到最少客户的窗口
            int min_queue = 0;
            for (int j = 1; j < num_windows; j++) {
                if (windows[j]->count < windows[min_queue]->count) {
                    min_queue = j;
                }
            }

            // 客户完成时间更新
            if (windows[min_queue]->count == 0) {
                customer->finish_time = current_time + customer->service_time;
            } else {
                Customer *last_customer = windows[min_queue]->queue[(windows[min_queue]->rear - 1 + MAX_CUSTOMERS) % MAX_CUSTOMERS];
                customer->finish_time = last_customer->finish_time + customer->service_time;
            }

            // 客户完成后，计算逗留时间
            total_stay_time += (customer->finish_time - customer->arrival_time);
            num_customers++; // 增加客户数量

            // 入队到对应窗口
            enqueue(windows[min_queue], customer);
        }

        // 检查每个窗口的客户完成情况并出队
        for (int j = 0; j < num_windows; j++) {
            if (windows[j]->count > 0) {
                Customer *serving_customer = windows[j]->queue[windows[j]->front];
                // 如果当前时间大于或等于客户完成时间，出队
                if (current_time >= serving_customer->finish_time) {
                    Customer *completed_customer = dequeue(windows[j]);
                    free(completed_customer); // 释放出队客户的内存
                }
            }
        }

        // 当前时间增加
        current_time++;
    }

    // 计算平均逗留时间
    if (num_customers > 0) {
        double average_stay_time = (double)total_stay_time / num_customers;
        printf("平均客户逗留时间: %.2f\n", average_stay_time);
    } else {
        printf("没有客户到达，无法计算平均逗留时间。\n");
    }
}

int main() {
    srand(time(NULL)); // 随机数种子
    int num_windows = MAX_WINDOWS;

    // 初始化窗口队列
    Queue *windows[MAX_WINDOWS];
    for (int i = 0; i < num_windows; i++) {
        windows[i] = (Queue *)malloc(sizeof(Queue));
        initQueue(windows[i]);
    }

    // 运行模拟
    simulateBank(windows, num_windows);

    // 释放内存
    for (int i = 0; i < num_windows; i++) {
        while (windows[i]->count > 0) {
            Customer *customer = dequeue(windows[i]);
            free(customer); // 释放队列中剩余客户的内存
        }
        free(windows[i]); // 释放窗口队列的内存
    }

    return 0;
}
