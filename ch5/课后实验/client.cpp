#include "client.h"
//自己写的头文件用" " 引用 系统自带的头文件用< >
void Client::ChangeServerName(char name) {
	Client::ServerName = name;
	Client::ClientNum ++;
}
int Client::getClientNum() {
	return Client::ClientNum;
}
//引用静态数据成员——"类名::"
//在client.cpp中实现类