/*
1. 栈区
    用于存储函数的局部变量，函数调用参数，返回地址等。
    栈的内存分配和释放由编译器自动完成
    栈区内存是按先进后出方式分配的，每次函数调用时分配空间，函数返回时释放‘

2. 堆区
    用于动态分配的内存（通过malloc，realloc，calloc等分配）
    堆的大小可在运行时动态扩展和缩小
    堆区由程序员显式管理，未释放的内存会造成内存泄漏

3. 全局静态区
    数据段（Data Segment）
    包含程序中已初始化的全局变量和静态变量。
    未初始化数据段（BSS Segment）
    存放未初始化的全局变量和静态变量，这些变量会被自动初始化为0。

4. 代码区
    程序执行代码存放在代码区，其值不能修改
*/