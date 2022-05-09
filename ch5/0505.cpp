//例5-8  常数据成员举例

#include <iostream>
using namespace std;
class A {
public:
       A(int i);
       void print();
private:
       const int a;
       static const int b;  //静态常数据成员 属于整个类
};
 
const int A::b=10; //在类体中证明 在类外定义和初始化 初始化之后不可在改变
A::A(int i) : a(i) { } //构造函数初始化列表 只能在初始化的时候给a赋值 

void A::print() {
  cout << a << ":" << b <<endl;
}

int main() {
//建立对象a和b，并以100和0作为初值，分别调用构造函数，
//通过构造函数的初始化列表给对象的常数据成员赋初值
  A a1(100), a2(0); //构造对象a1是把100传给a 调用构造函数进行初始化

  a1.print();
  a2.print();
  return 0;
}



