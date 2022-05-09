#include <iostream>
#include <cstdlib> //为了使用伪随机数函数调用的头文件
using namespace std;

/*枚举 enum 枚举名 {枚举元素1,枚举元素2,...};
第一个枚举成员的默认值为整型的 0，后续枚举成员的值在前一个成员上加 1
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
我们在这个实例中把第一个枚举成员的值定义为 1，第二个就为 2，以此类推
*/
enum GameStatus  //游戏有三种状态先定义好 
{
    WIN,
    LOSE,
    PLAYING
};

//写函数 投两次骰子求和
int rollDice()
{
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    //随机生产一个整数 但是要把随机生成的整数控制在1-6之间 就用取余数来解决
    //任何整数 对6取余数结果都是0-5 所以两次投骰子应该再rand()%6基础上加1
    int sum = die1 + die2;
    cout << "player rolled " << die1 << "+" << die2 << "=" << sum << endl;
    return sum;
}

/*
rand函数
  函数原型：int rand(void)；
  所需头文件：<cstdlib>
  功能和返回值：求出并返回一个伪随机数
  默认情况下 种子都是一样的 所以产生的随机数序列都一样
 
srand函数
  void srand(unsigned int seed);
  参数：seed产生随机数的种子
  所需头文件：<cstdlib>
  功能：为使rand()产生一序列伪随机整数而设置起始点。使用1作为seed参数，可以重新初化rand()。
*/

int main()
{
    int sum, mypoint;
    GameStatus status; //枚举的类型定义为GameStatus 枚举变量定义为status
    unsigned seed;
    int rollDice();
    cout << "plz enter an unsigned integer: ";
    cin >> seed;      //随机数传给种子seed
    srand(seed);      //用seed生成一个随机的序列
    sum = rollDice(); 
    //用上面生成的随机序列传给rollDice函数 求第一轮投两个骰子的和数
    //就是有了用户的一个seed 就有一个确定的rand的随机序列 
    //这个rand就是rollDice里面用的rand()

    switch (sum)
    {
    case 7:
    case 11:
        status = WIN;
        break;
    case 2:
    case 3:
    case 12:
        status = LOSE;
        break;

    default:
        status = PLAYING; //如果不是以上的状态就继续玩
        mypoint = sum;  //把这一轮两个点数和赋给mypoint
        cout << "point is " << mypoint << endl;
        break;
    }

    while (status == PLAYING) //状态分不出输赢就继续玩
    {
        sum = rollDice(); //再模拟两次投骰子 求和数 调用一次rollDice()就相当于投两次骰子
        if (sum == mypoint)
            status = WIN;
        else if (sum == 7)
            status = LOSE;
    }

    if (status == WIN)
        cout << "player wins" << endl;
    else
        cout << "player loses" << endl;

    return 0;
}