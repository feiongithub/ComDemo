
#ifndef IMPLEMENT_H_
#define IMPLEMENT_H_


#include "Interface.h"

// 实际应用时，CWork实现类就放在 dll里 
class CWork : public IOuternal , public IInternal
{
private:
	char _p[0x10];
	ULONG _ref;
public:
	CWork():_ref(0)
	{
		_p[0]='\0';
	}

public:
	virtual const char* GetName()
	{
		return _p;
	}
	virtual BOOL SetName(const char* str, size_t len)
	{
		if( len >0x010 )	return FALSE;
		memcpy_s(_p,0x10,str,len);
		_p[len]='\0';
		return TRUE;
	}
	STDMETHOD_(ULONG, AddRef)() {  return InterlockedIncrement(&_ref);}
	STDMETHOD_(ULONG, Release)() 
	{ 
		ULONG ref = InterlockedDecrement(&_ref); 
		if (0 == ref)
		{ 
			delete this; 
		} 
		return ref; 
	}
	STDMETHOD(QueryInterface)( REFIID iid, PVOID * ppv )
	{
		if( ppv == NULL )	return E_INVALIDARG;
		*ppv = NULL;
		if( iid == IID_IOuternal)	
		{
			*ppv = static_cast<IOuternal*>(this);
			this->AddRef();
			return S_OK;
		}
		else if (iid == IID_IInternal )
		{
			*ppv = static_cast<IInternal*>(this);
			this->AddRef();
			return S_OK;
		}
		return E_NOTIMPL;
	}
};

// 实际应用 就从dll导出该函数 
IOuternal* WINAPI GetInstance(REFIID riid)
{
	IOuternal* p = new(std::nothrow) CWork();
	if( NULL == p )return NULL;
	p->AddRef();
	void* query = NULL;
	if( p->QueryInterface(riid,&query)== S_OK )
	{
		p->Release();
		return static_cast<IOuternal*>(query);
	}
	p->Release();
	return NULL;

}


#endif