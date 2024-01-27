#ifndef HASPTR
#define HASPTR
// ��Ϊ����ֵ�� HasPtr ��
#include<iostream>
#include<string>
#include<vector>
#include<memory>
class HasPtr
{
	friend void swap(HasPtr&, HasPtr&);
public:
	// ���캯��
	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) {}
	HasPtr(std::string& _s, int _i) : 
		ps(new std::string(_s)), i(_i) {}
	// �������캯��
	HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
	bool operator<(const HasPtr& rhs);
	// ������ֵ�����
	HasPtr& operator=(const HasPtr&);

	void print()
	{
		std::cout << i << std::endl;
	}
	// ��������
	~HasPtr()
	{
		delete ps;
	}
private:
	std::string* ps;
	int i;
};

// ������ֵ�����
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	std::string* new_ps = new std::string(*rhs.ps);
	delete ps;
	ps = new_ps;
	i = rhs.i;
	return *this;
}

bool HasPtr::operator<(const HasPtr& rhs)
{
	return i < rhs.i;
}

inline
void swap(HasPtr& lhs, HasPtr& rhs)
{
	using std::swap;
	// ����ָ��
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}
#endif // HASPTR