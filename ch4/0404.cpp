//结构体表示学生的基本信息
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//学生信息结构体
struct Student
{
    int num;
    string name;
    char sex;
    int age;
};

int main(){
    Student stu={9700,"yly",'f',19};
    cout << "num: " << stu.num <<endl;
    cout << "num: " << stu.age <<endl;
    cout << "num: " << stu.name <<endl;
    cout << "num: " << stu.sex <<endl;

    return 0;
}


