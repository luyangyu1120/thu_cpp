//定义CPU类
#include<iostream>
using namespace std;

enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7}; //定义枚举类
class CPU{
    public:
    //有参数构造函数
    CPU(CPU_Rank r, int f, float v){
        rank = r;
        frequency = f;
        voltage =v;
        cout << "调用CPU构造函数" << endl;
    }
    //析构函数
    ~CPU(){cout << "析构CPU构造函数" << endl;}

    //外部接口函数
    //访问三个成员
    CPU_Rank GetRank() const{return rank;}
    int Getfrequency() const{return frequency;}
    float Getvoltage() const{return voltage;}

    //设置三个成员
    void SetRank(CPU_Rank r) {rank = r;}
    void Setfrequency(int f) {frequency = f;}
    void Setvoltage(float v) {voltage = v;}

    void Run() {cout << "CPU开始运行" << endl;}
    void Stop() {cout << "CPU停止运行" << endl;}

    private: //类里面就是这三个变量在用 r f 和v都是外部传给rank frequency和voltage的形参
    CPU_Rank rank; //CPU_Rank类型
    int frequency;
    float voltage;
};

enum RAM_Type {DDR2=2, DDR3, DDR4};
class RAM{
    public:
    //有参构造函数
    RAM(RAM_Type t, unsigned int f, unsigned int s){
        type = t;
        frequency = f;
        size = s;
        cout << "构建一个RAM" << endl;
    }
    ~RAM(){cout << "析构一个RAM" << endl;}

    //查看三个成员
    RAM_Type GetType() const{return type;}
    unsigned int Getfrequency() const{return frequency;}
    unsigned int Getsize() const{return size;}

    //给三个成员赋值
    void Settype(RAM_Type t) {type = t;}
    void Setfrequency(unsigned int f) {frequency = f;}
    void Setsize(unsigned int s) {size =s;}

    void Run() {cout << "开始RAM" << endl;}
    void Stop() {cout << "结束RAM" << endl;}

    private:
    RAM_Type type;
    unsigned int frequency;
    unsigned int size;

};

enum CDROM_Interface {SATA,USB};
enum CDROM_Install_type {external,built_in};
class CD_ROM
{
private:
	enum CDROM_Interface interface_type;
	unsigned int cache_size;//MB
	CDROM_Install_type install_type;

public:
    CD_ROM (CDROM_Interface i, unsigned int s,  CDROM_Install_type it)
	{
		interface_type = i;
		cache_size = s;
		install_type = it;
		cout << "运行CD_ROM构造函数" << endl;
	}
	~CD_ROM () { cout << "析构CD_ROM" << endl; }

    CDROM_Interface GetInterfaceType() const { return interface_type; }
    unsigned int GetSize() const { return cache_size; }
	CDROM_Install_type GetInstallType() const { return install_type; }

    void SetInterfaceType(CDROM_Interface i) { interface_type = i; }
    void SetSize(unsigned int s) { cache_size = s; }
    void SetInstallType(CDROM_Install_type it) { install_type = it; }

    void Run() {cout << "开始CD_ROM" << endl; }
	void Stop() {cout << "结束CD_ROM" << endl; }

};

class COMPUTER
{
private:
	CPU my_cpu;
	RAM my_ram;
	CD_ROM my_cdrom;
	unsigned int storage_size;//GB
	unsigned int bandwidth;//MB

public:
	COMPUTER (CPU c, RAM r, CD_ROM cd,unsigned int s,unsigned int b);
	~COMPUTER () { cout << "析构COMPUTER构造函数!" << endl; }

	void Run() 
	{
		my_cpu.Run();
		my_ram.Run();
        my_cdrom.Run();
		cout << "运行COMPUTER!" << endl; 
	}

	void Stop() 
	{
		my_cpu.Stop();
		my_ram.Stop();
        my_cdrom.Stop();
		cout << "结束COMPUTER" << endl; 
	}

};

//构造函数的实现
COMPUTER::COMPUTER(CPU c, RAM r, CD_ROM cd,unsigned int s,unsigned int b):
	       my_cpu(c),my_ram(r),my_cdrom(cd)
{
	storage_size = s;
	bandwidth = b;

	cout << "构造COMPUTER函数!" << endl;
}


int main()
{
	CPU a(P6,300,2.8);
	a.Run();
	a.Stop();
	cout<<"*************************\n";


	RAM b(DDR3,1600,8);
	b.Run();
	b.Stop();
	cout<<"*************************\n";

	CD_ROM c(SATA,2,built_in);
	c.Run();
	c.Stop();
	cout<<"*************************\n";

	COMPUTER my_computer(a,b,c,128,10);
	cout<<"*************************\n";

	my_computer.Run();
	my_computer.Stop();
	cout<<"*************************\n";

	return 0;
}


/*
int main(){
    CPU a(P1,300,2.8);
    a.Run();
    a.Stop();
    //析构函数是在return 0;运行之前运行的 析构空间之后 才会结束主程序main
    return 0;
}*/