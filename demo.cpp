// demo.cpp : 定义控制台应用程序的入口点。
//


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


    // 接下来是 dll 中的操作，操作实例
    // 这里的例子是保存了一个字符串 abc
	IInternal* inter = NULL;
	if( S_OK == outer->QueryInterface(IID_IInternal,(PVOID*)&inter) )
	{
		inter->SetName("abc",3);
		inter->Release();
	}


    // 外部使用者可以获取这个值
	printf("After: %s\n",outer->GetName());
	outer->Release();
	return 0;
}

