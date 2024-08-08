#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int n, m;
    n = 11;  // 共11个人  
    m = 3;   // 数到3，出队！

    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }
    printf("初始化队列后，队头编号=%d\n", q.front());

    // 从1开始报数
    int cnt = 1;
    while (!q.empty()) {
        if (cnt % m == 0) {
            // 点到这个人了
            printf("cnt=%d, 出队编号=%d, 还剩人数=%d\n", cnt, q.front(),
                   q.size() - 1);
            q.pop();
        } else {
            // 没点到，就把队头放到队尾，就当是循环队列了
            q.push(q.front());
            q.pop();
        }
        cnt++;
    }
    return 0;
}