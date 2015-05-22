// demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <windows.h>
#include <tchar.h>
#include <algorithm>
#include "Interface.h"
#include "Implement.h"


int _tmain()
{
	// GetInstance 实际应用时应该是 LoadLibrary GetProcAddress 结合使用 得到的函数
	IOuternal* outer = GetInstance(IID_IOuternal);
	printf("Before: %s\n",outer->GetName());

	IInternal* inter = NULL;
	if( S_OK == outer->QueryInterface(IID_IInternal,(PVOID*)&inter) )
	{
		inter->SetName("abc",3);
		inter->Release();
	}

	printf("After: %s\n",outer->GetName());
	outer->Release();
	return 0;
}

