
#ifndef INTERFACE_H_
#define INTERFACE_H_


// 使用VS工具生成GUID，直接拷贝到此
// {3CD49811-FDC6-4AB0-A4E8-111476DAA2F7}
static const GUID IID_IOuternal = 
{ 0x3cd49811, 0xfdc6, 0x4ab0, { 0xa4, 0xe8, 0x11, 0x14, 0x76, 0xda, 0xa2, 0xf7 } };

class IOuternal : public IUnknown // 外部调用
{
public:
	virtual const char* GetName()= 0;
};



// 实际应用的时候，IInternal可以放在内部使用，外部只使用IOuternal
// 内部使用 IInternal 可以方便在内部传递实例,只需传递指针即可
// {A6179295-960E-4D04-B3C1-C4B2A240CE17}
static const GUID IID_IInternal = 
{ 0xa6179295, 0x960e, 0x4d04, { 0xb3, 0xc1, 0xc4, 0xb2, 0xa2, 0x40, 0xce, 0x17 } };
class IInternal : public IUnknown // 对内使用
{
public:
	virtual BOOL SetName(const char* str, size_t len) = 0;
};

#endif