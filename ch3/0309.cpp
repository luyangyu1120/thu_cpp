//求组合数
//组合数公式
//(n,k)=(n-1,k)+(n-1,k-1)
//当n=k (n,k)=1 当n<k或者k=0 (n,k)=0

#include <iostream>
using namespace std;

int C(int n, int k)
{
    if (n == k || k == 0) //n=k或者k=0
    {
        return 1;
    }
    else if (n < k )
    {
        return 0;
    }
    else if (n > k)
    {
        return C(n - 1, k) + C(n - 1, k - 1);
    }
    else 
    return 0;
}

//如果只有else if (n > k){return C(n - 1, k) + C(n - 1, k - 1);}
//没有else return 0;
//那就是函数存在没有返回值的情况 如果输入一个n和k不满足if 和 else if中的任何一个条件 
//那么就没有返回值了 这个函数 就是有问题的 
//所以除了上面的if 和 else if对应的条件 还应该有个else return 0；这个函数才完整

int main(){
    int n,k;
    cout << "从n个人取k" << endl;
    cout << "n= " << endl;
    cin >> n;
    cout << "k= " << endl;
    cin >>  k;
    cout << "result = " << C(n,k) << endl;
    return 0;
}