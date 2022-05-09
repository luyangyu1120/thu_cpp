//函数的递归调用
//求阶乘的函数

//n=0 n!=1
//n!=0 n!=fun(n-1)*n

#include<iostream>
using namespace std;

int fun(int a){
    int result;
    if (a==0)
        result=1; //递归一定有一个终结点 阶乘的终结点就是0!=1
    else if (a > 0)
        result = a*fun(a-1); //实现递归功能在函数内部再次调用函数
    return result;
}

int main(){
    int n;
    cout<<"enter n "<<endl;
    cin >> n;
    cout << "result is " << fun(n);
    return 0;
}