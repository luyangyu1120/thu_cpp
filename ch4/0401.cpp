//类定义
#include <iostream>
using namespace std;
class Clock
{
public:
    Clock(int newH, int newM, int newS); //构造函数
    //构造函数的名字和类保持一致
    //构造函数可以有很多参数
    //没有返回类型 也不能有void
    Clock();//默认构造函数

    //两个Clock是重载函数 函数名可以相同
    void setTime(int newH, int newM, int newS);
    void showTime();

private:
    int hour, minute, second;
};
//构造函数的实现
//初始化列表 对类的成员变量进行初始化
// newH初始化hour 这种列表初始化比在函数体里效率高
Clock::Clock(int newH, int newM, int newS) : hour(newH), minute(newM), second(newS) {} //后面只有一个{}里面什么都不写
Clock::Clock():hour(0),minute(0),second(0) {} //由于Clock()里面没有参数 所以初始化就用一个约定的初始值就行 这里是0

void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}
void Clock::showTime()
{
    cout << hour << ":" << minute << ":" << second << endl;
}

//主函数
int main()
{
    Clock c1(8, 30, 20); //自动调用有参数的构造函数
    //构造函数就是为了给自定义的类中的变量初始化的
    //c1有参数 程序会自动把c1传到Clock::Clock(int newH, int newM, int newS)这个有参数的构造函数中去

    Clock c2; //调用无参数的构造函数
    //不管给没给参数 构造一个对象的时候 都要调用一个构造函数
    //如果有参数 就调用有参数的构造函数 如果没有参数 就调用没有参数的默认的构造函数
    //所以一般来讲 都要为类写一个无参数的默认构造函数 因为其他人使用类的时候 经常会构造一个对象但是不给初始值
    //比如int a; 就完事了 定义int下的对象a 一般都没有给a初始化 
    c1.showTime();
    c2.showTime();
    return 0;
}
