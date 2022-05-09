//引用传递是参数之间的双向传递
//值传递是参数之间的单向传递 一个函数return就一个值
#include<iostream>
using namespace std;

//定义交换函数
void swap(int a, int b){
    int t = a;
    a = b;
    b = t;
}
//x和y赋值给a和b之后 就开始swap函数内进行运算 但是普通的赋值运算在函数内与主程序是完全割裂的 
//所以x和y赋值给 a和b之后与ab就没有联系了 swap就交换了ab的值 但是x和y根本没有改变
//xy是主函数的变量 ab是子函数的变量 xy和ab之间的传递关系是单向的  只在主函数调用子函数时候用一下 之后就再也没有联系了
//定义之后 ab就是xy 再子函数里交换ab 就相当于交换了主函数中的xy 在主函数调用函数之后就交换了xy

void swap2(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
//在a和b前面用&表示引用 就是a和b已经预备着做某两个变量的引用 但是没有主函数时候还不知道ab是谁的引用
//当主函数定义了xy之后 再调用子函数 就表示了ab是xy的引用


int main(){
    int x=50;
    int y=100;
    cout << "x= " << x << " " << "y= " << y <<endl;
    swap2(x,y);
    cout << "x= " << x << " " << "y= " << y <<endl;
    return 0;
}