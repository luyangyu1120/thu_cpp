//例4-4 类的组合，线段（Line）类
//4_4.cpp
#include <iostream>
#include <cmath>
using namespace std;

//Point类定义
class Point { 
public:
Point(int xx = 0, int yy = 0) {x = xx; y = yy; cout << "调用Point的构造函数" << endl;} //有参数构造函数
Point(Point &p); //复制构造函数
~Point(){cout << "调用Point的析构函数" << endl;} //析构函数调用

int getX() { return x; }
int getY() { return y; }
private:
int x, y;
};

//复制构造函数的实现
Point::Point(Point &p) { 
x = p.x;
y = p.y;
cout << "调用Point的复制构造函数" << endl;
}

//类的组合
//Line类的定义
class Line { 
public: //外部接口
Line(Point xp1, Point xp2); //有参数构造函数
Line(Line &l); //复制构造函数 
~Line(){cout << "调用Line的析构函数" << endl;} //析构函数调用

double getLen() { return len; }
private: //私有数据成员
Point p1, p2; //Point类的对象p1,p2
double len;
};

//组合类的构造函数
Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
cout << "调用Line的构造函数" << endl;
double x = static_cast<double>(p1.getX() - p2.getX());
double y = static_cast<double>(p1.getY() - p2.getY());
len = sqrt(x * x + y * y);
}
//组合类的复制构造函数
Line::Line (Line &l): p1(l.p1), p2(l.p2) {
cout << "调用Line的复制构造函数" << endl;
len = l.len;
}

//主函数
int main() {
Point myp1(1, 1), myp2(4, 5); //建立Point类的对象
Line line(myp1, myp2); //建立Line类的对象 两点确定一条直线 所以Line类只需要两个点作为参数就行
Line line2(line); //利用复制构造函数建立一个新对象
cout << "The length of the line is: ";
cout << line.getLen() << endl;
cout << "The length of the line2 is: ";
cout << line2.getLen() << endl;
return 0;
}

//析构的顺序和构造的顺序是相反的 
//现有子体 才能构造母体
//母体被析构之后 子体才能获得自由 进一步被析构
//把外面包装拆了才能拆里面的 打包和拆快递一个道理