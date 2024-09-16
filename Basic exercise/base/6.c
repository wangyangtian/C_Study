#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool fun(int n){
    if(n%3==0&&n%5==0){
        printf("可以同时被3和5整除。");
        return true;
    }
    else{
        printf("不可以同时被3和5整除。");
        return false;
    }
            
}

int main() {
    fun(15);
    return 0;
}