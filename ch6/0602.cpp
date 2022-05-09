//求斐波那契数列前20项 存在数组里
#include<iostream>
using namespace std;

int main(){
    int f[20]={1,1}; //初始化数组下标0和1的两个元素 
    for(int i=2;i<20;i++){
        f[i]=f[i-1]+f[i-2];
    }
    //每行输出5个数
    for(int i=0;i<20;i++){
        if(i%5==0) cout<<endl;
        cout.width(12); //设置输出宽度
    cout << f[i] ;
    }
    return 0;
}

