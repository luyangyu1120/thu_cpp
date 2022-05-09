//复制构造函数
#include <iostream>
using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
        cout << "Calling the 构造函数" << endl;
    }                      //有参数构造函数
    Point(const Point &p); //复制构造函数

    void setX(int xx) { x = xx; }
    void setY(int yy) { y = yy; }

    int getX() const { return x; }
    int getY() const { return y; }

private:
    int x, y;
};

//成员函数的实现
//函数名是类名 且没有返回值
Point::Point(const Point &p)
{
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor" << endl;
}

void fun1(Point p)
{
    cout << p.getX() << endl;
}

Point fun2()
{
    Point q(7, 8);
    return q;
}

int main()
{

    Point a(3, 5); //定义一个Point类的对象a
    Point b(a);    //用a来初始化对象b 第一次调用复制构造函数
    cout << b.getX() << endl;
    fun1(b);    //第二次调用复制构造函数
    b = fun2(); //这里没有用复制构造函数 ？？？？
    //注意：在有些编译环境下，上面运行结果可能不尽相同，因为编译器有时会针对复制构造函数的调用做优化，避免不必要的复制构造函数的调用。
    //故这里本应该有复制构造函数的调用的，但由于编译器进行了优化，没有调用复制构造函数。

    cout << b.getX() << endl;
    return 0;
}

