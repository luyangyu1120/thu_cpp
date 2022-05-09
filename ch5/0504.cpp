//例5-7  常成员函数举例

#include <iostream>
using namespace std;

class R
{
public:
    R(int r1, int r2) : r1(r1), r2(r2) {}
    void print();
    void print() const; //常函数 合法的重载形式 因为有const作为标志 参数表是可以一样的
private:
    int r1, r2;
};

void R::print()
{ //没有const后缀 如果这个函数有改变r1和r2的语句 不会报错
    //r1 = r1 + 1; 因为不是常函数 所以允许改变对象的状态 加上这条语句不会报错
    cout << r1 << ":" << r2 << endl;
}
//常函数是为了处理常对象
void R::print() const
{ //这个函数绝不改变对象的状态 如果这个函数有改变r1和r2的语句 编译器会报错
    //r1 = r1 + 1; 加上这条语句会报错
    cout << r1 << ";" << r2 << endl;
}

int main()
{
    R a(5, 4);
    a.print(); //调用void print() 如果删除void print()只保留void print() const
    // a.print(); 也会调用void print() const
    //如果一个函数 本意就是不改变对象的状态 可以只写成常函数就好了 方便

    const R b(20, 52); //常对象 一旦定义的时候初始化 就不会被修改
    b.print();         //调用void print() const
    return 0;
}
