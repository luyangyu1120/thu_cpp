//例5-9  常引用作形参
//解决0503.cpp的问题

#include <iostream>
#include <cmath>
using namespace std;
class Point
{       // Point类定义
public: //外部接口
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int getX() { return x; }
    int getY() { return y; }
    friend float dist(const Point &p1, const Point &p2); //常引用 在参数前面加const 只读引用 只能用不能修改
private:                                                 //私有数据成员
    int x, y;
};

float dist(const Point &p1, const Point &p2)
{
    //p1.x=p1.x + 1; 报错显示p1.x是一个不可修改的值
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return static_cast<float>(sqrt(x * x + y * y));
}

int main()
{ //主函数
    const Point myp1(1, 1), myp2(4, 5);
    cout << "The distance is: ";
    cout << dist(myp1, myp2) << endl;
    return 0;
}
