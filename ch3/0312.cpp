/*内联函数是提高简单函数效率的一种机制
内联函数
  声明时使用关键字 inline。
  编译时在调用处用函数体进行替换，节省了参数传递、控制转移等开销。
  注意：
  内联函数体内不能有循环语句和switch语句；
  内联函数的定义必须出现在内联函数第一次被调用之前；
  对内联函数不能进行异常接口声明。
inline只是对编译器的一种建议 现在的编译器都有自己的优化过程 有时候写了inline编译器不一定理会 有些简单函数没有写inline 但是编译器也会当成inline处理
*/

//如果函数是inline内联函数 在主函数里面就不需要有调用再返回的过程 而是以一种恰当的方式 把内联函数的运行直接嵌套进主函数
//相当于一个简单简单函数的缩写 缩减

#include <iostream>
using namespace std;
const double PI = 3.14159265358979;

inline double calArea(double radius)
{
    return PI * radius * radius;
}
int main()
{
    double r = 3.0;
    double area = calArea(r);
    cout << area << endl;
    return 0;
}
