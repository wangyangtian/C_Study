#include <iostream>
using namespace std;

struct SString {
    char ch[100];  // 假设最大长度为100
    int length;    // 实际字符串长度
};

int Index_2(SString s, SString t) {
    int i = 1;  // 从1开始
    int j = 1;  // 从1开始
    while (i <= s.length - t.length + 1) {  // 修改循环条件，确保能够匹配到最后一个可能的位置
        if (s.ch[i] == t.ch[j]) {
            i++;
            j++;
            if (j > t.length)  // j超过模式串长度时匹配成功
                return i - t.length;
        } else {
            i = i - j + 2;  // i回退到下一起始位置
            j = 1;          // j重置为1
        }
    }
    return 0;
}

int main() {
    // 测试用例1
    SString s1 = {{' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}, 8}; // 注意第一个位置是空格
    SString t1 = {{' ', 'd', 'e', 'f'}, 3};
    cout << "Index: " << Index_2(s1, t1) << endl; // 应该输出4

    // 测试用例2
    SString s2 = {{' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}, 8}; // 注意第一个位置是空格
    SString t2 = {{' ', 'a', 'b', 'c'}, 3};
    cout << "Index: " << Index_2(s2, t2) << endl; // 应该输出1

    // 测试用例3
    SString s3 = {{' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}, 8}; // 注意第一个位置是空格
    SString t3 = {{' ', 'h'}, 1};
    cout << "Index: " << Index_2(s3, t3) << endl; // 应该输出8

    // 测试用例4
    SString s4 = {{' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}, 8}; // 注意第一个位置是空格
    SString t4 = {{' ', 'i'}, 1};
    cout << "Index: " << Index_2(s4, t4) << endl; // 应该输出0，因为没有匹配

    return 0;
}
