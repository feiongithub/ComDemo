// demo.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include <windows.h>
#include <tchar.h>
#include <algorithm>
#include "Interface.h"
#include "Implement.h"


int _tmain()
{
	// GetInstance ʵ��Ӧ��ʱӦ���� LoadLibrary GetProcAddress ���ʹ�� �õ��ĺ���
	IOuternal* outer = GetInstance(IID_IOuternal);
	printf("Before: %s\n",outer->GetName());


    // �������� dll �еĲ���������ʵ��
    // ����������Ǳ�����һ���ַ��� abc
	IInternal* inter = NULL;
	if( S_OK == outer->QueryInterface(IID_IInternal,(PVOID*)&inter) )
	{
		inter->SetName("abc",3);
		inter->Release();
	}


    // �ⲿʹ���߿��Ի�ȡ���ֵ
	printf("After: %s\n",outer->GetName());
	outer->Release();
	return 0;
}

