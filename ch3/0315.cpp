//带默认参数值的函数


#include <iostream>
#include <iomanip>
using namespace std;
int getVolume(int length, int width = 2, int height = 3);
//声明函数的原型
 
int main() {
const int X = 10, Y = 12, Z = 15;
cout << "Some box data is " ;
cout << getVolume(X, Y, Z) << endl;
cout << "Some box data is " ;
cout << getVolume(X, Y) << endl;
cout << "Some box data is " ;
cout << getVolume(X) << endl;
return 0;
}

//函数定义在主函数之后
int getVolume(int length, int width, int height) 
{
    cout << setw(5) << length << setw(5) << width << setw(5) << height << '\t';
return length * width * height;
}
//setw()用于控制输出之间的空格 但是要引用头文件#include <iomanip>

//不能把声明函数原型和定义函数都写默认值
//第一种情况 函数声明+默认值 主函数 函数定义
//第二种情况 函数定义+函数默认值 主函数



