//静态数据成员
#include<iostream>
using namespace std;

class Point
{
private:
    int x, y; //一个点的两个分坐标
    static int count; //静态数据成员声明，用于记录点的个数 在class中声明静态数据成员
    //整个class中共享一个count来记录共有几个点

public:
    
    Point(int x = 0, int y = 0):x(x) ,y(y){count++; cout << "调用构造函数" << endl;} //构造函数 每构造一个点 点的总数就+1
    Point(Point&p){x=p.x; y=p.y; count++; cout << "调用复制构造函数" << endl;} //复制构造函数 每复制构造一个点 点的总数就+1
    ~Point(){
        count--;
        cout << "调用析构函数" << endl;
        cout << "此时还有" << count << "个点" << endl; //可以追踪析构的过程
    } 
    //析构函数 每析构一个点 点的总数就-1
    //很多时候 析构函数和构造函数的 操作时相对的count++ 与count--

    int getX() {return x;}
    int getY() {return y;}
    //输出静态数据成员
    void showCount() {cout << "一共有" << count << "个点" << endl;}
};

int Point::count = 0; //在类外进行静态数据成员定义和初始化，使用类名限定

int main(){
    Point a(4,5);
    cout << "点A的坐标是" << a.getX() << "," << a.getY() << endl;
    a.showCount();

    Point b(a); //调用复制构造函数 cout还是自增加一个
    cout << "点B的坐标是" << b.getX() << "," << b.getY() << endl;
    b.showCount();

    //在return 0；结束之前 分别一次一次地调用析构函数 
    //清除掉A和B两个点的内存 count也依次-1
    return 0;
}

//count是私有变量 在class之外只能用 对象名.函数名 才能调用
//如果不定义点 就相当于count是0 但是这时候不能查看 因为count是私有变量 在class外不能访问
//只有通过接口函数showCount()才能看到count是几
//而showCount()的调用 只能是对象名.showCount() 既然没有定义对象 就不可能调用showCount函数 自然就不可能看到 count是几

//解决办法在后面