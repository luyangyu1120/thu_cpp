#include<iostream>
using namespace std;

//求平方函数
int fun2(int m){
    return m * m;
}

//求平方和函数
int fun1(int x , int y){
    return fun2(x) + fun2(y); //调用fun2()函数 
}

//主函数
int main(){
    int a ,b;
    cout << "enter a and b " << endl;
    cin >> a >> b ;
    cout << "sum is "<< fun1(a,b) << endl;
    return 0;
}