//函数重载的概念
//C++允许功能相近的函数在相同的作用域内以相同函数名声明，从而形成重载。方便使用，便于记忆。
//功能相似的函数可以用同样的名字

//合法重载函数一 参数类型不同
int add(int x, int y); //两个整数相加
double add(double x, double y); //两个浮点数相加

//合法重载函数二 形参个数不同
int add(int x, int y);
int add(int x, int y, int z);

//两个功能完全不一样的函数不能表示重载函数 用同一个函数名 只会引起误会和混淆
#include <iostream>
using namespace std;
int sumOfSquare(int a, int b) {
    return a * a + b * b;
}
double sumOfSquare(double a, double b) {
    return a * a + b * b;
}
int main() {
    int m, n;
    cout << "Enter two integer: ";
    cin >> m >> n;
    cout<<"Their sum of square: "<<sumOfSquare(m, n)<<endl;
    double x, y;
    cout << "Enter two real number: ";
    cin >> x >> y;
    cout<<"Their sum of square: "<<sumOfSquare(x, y)<<endl;
    return 0;
}

