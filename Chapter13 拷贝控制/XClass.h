#ifndef XCLASS
#define XCLASS

#include<iostream>
#include<string>
#include<vector>
#include<memory>
struct X
{
	// ���캯��
	X()  { std::cout << "X()" << std::endl; }
	// �������캯��
	X(const X& )  { std::cout << "X(const X&)" << std::endl; }

	// ������ֵ�����
	X& operator=(const X& ) 
	{ 
		std::cout << "X& operator=(const X&)" << std::endl; 
		return *this; 
	}
	// ��������
	~X() 
	{ 
		std::cout << "~X()" << std::endl; 
	}
};


#endif // HASPTR