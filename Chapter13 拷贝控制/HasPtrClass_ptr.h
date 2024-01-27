#ifndef HASPTR
#define HASPTR
// ��Ϊ����ָ��� HasPtr ��
#include<iostream>
#include<string>
#include<vector>
#include<memory>
class HasPtr
{
public:
	// ���캯��
	HasPtr(const std::string &s = std::string()): 
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	// �������캯��
	HasPtr(const HasPtr& orig) : 
		ps(new std::string(*orig.ps)), i(orig.i), use(orig.use) 
	{
		// �������ü���
		++*use;
	}
	// ������ֵ�����
	HasPtr& operator=(const HasPtr&);
	// ��������
	~HasPtr() {}
private:
	std::string* ps;
	int i;
	// use ������ʾ���ü�����ֵ
	std::size_t* use;
};

// ������ֵ�����
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	// �����Ҳ��������ü���ֵ
	++*rhs.use;
	// �ݼ�����������ü���ֵ����û�������û����ñ��������ͷű�����
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
	// �����ݴ� rhs ������������
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

// ������ֵ�����
HasPtr::~HasPtr()
{
	// ������ü�����Ϊ 0 
	if (--*use == 0)
	{
		// �ͷ� string �ڴ�
		delete ps;
		// �ͷż������ڴ�
		delete use;
	}
}

#endif // HASPTR