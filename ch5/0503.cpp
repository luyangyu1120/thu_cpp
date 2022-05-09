//例5-6 使用友元函数计算两点间的距离
#include <iostream>
#include <cmath>
using namespace std;

//定义点类
class Point
{
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {} //构造函数
    int getX() { return x; }
    int getY() { return y; }
    friend float dist(Point &a, Point &b); //友元 不是成员函数
};

//定义dist函数
//点类的xy都是私有成员 在外部不能直接访问 在外部只能用对象调用getX()和getY()来使用
//如果在使用时 一直调用getY()和getX()会影响执行效率

float dist(Point &a, Point &b)
// ab两个点的引用作为参数 不要直接传值 传值的时间空间成本比较高
//引用是双向传递 一旦在dist函数内部不小心改变了ab点的信息 就会把私有成员的信息改变了
//这个隐患后面例题会解决 0506.cpp
{
    double x = a.x - b.x;
    double y = a.y - b.y;
    return static_cast<float>(sqrt(x * x + y * y));
}

int main()
{
    Point p1(1, 1), p2(4, 5);
    cout << "The distance is: ";
    cout << dist(p1, p2) << endl;
    return 0;
}


/*友元类的例子*/
class A
{
    friend class B; 
    //授权B类的所有函数 可以直接使用A的private成员x
    //但是A不可以使用B的私有数据 因为A不是B的友元 友元是单向的关系
public:
    void display()
    {
        cout << x << endl;
    }

private:
    int x;
};

class B
{
public:
    void set(int i);
    void display();

private:
    A a;
};

void B::set(int i)
{
    a.x = i; //此时B可以直接使用A的对象a的私有数据x
}
void B::display()
{
    a.display();
};