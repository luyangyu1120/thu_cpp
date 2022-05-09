//汉诺塔函数递归问题
//A->B->C
#include<iostream>
using namespace  std;

//先定义模拟的转移过程 不用返回任何值 只要输出转移的过程就行
void move(char src, char des){
    cout << src << "————>" << des << endl;
}

//定义汉诺塔函数 进行递归 hanoi 不用返回任何值
//char是字符 不是字符串 所以只能用's'这样的字符才行 
void hanoi(int n, char src, char mid, char des){ //定义第一个位置放n个盘子 一共有三个位置
    if (n==1)
    {
        move(src,des);
    }
    else if(n>1)
    {
        hanoi(n-1,src,des,mid);
        move(src, des);
        hanoi(n-1, mid, src, des);
    }
}

//斐波那契数列第n项

int fun(int n){
    if (n==0)
    return 0;
    else if (n==1)
    return 1;
    else
    return fun(n-1)+fun(n-2);
}

//同时调用fun()和hanoi()函数

int main(){
    int m;
    cout << "enter the number in the desk " << endl;
    cin >> m;
    cout << "the steps is " << endl;
    hanoi(m,'A','B','C');

    for (int i = 0; i <= 10; i++)
    {
        cout << fun(i) << endl; //输出前11项 从0-10项
    }
    
    return 0;
}

//函数调用的次数是二叉树形式 一共有2^n-1次