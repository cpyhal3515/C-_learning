#ifndef STRING
#define STRING
// ���� String ����
#include<iostream>
#include<memory>
class String
{
public:
	// ���캯��
	String() : String("") {}
	String(const char*);

	// �������캯��
	String(const String&);
	// �ƶ����캯��
	String(String&&) noexcept;
	// ������ֵ�����
	String& operator=(const String&);
	// �ƶ���ֵ�����
	String& operator=(String&& rhs) noexcept;
	// ��������
	~String();
	
	
	// ������ʼָ��
	const char* c_str() const { return begin; }
	// ���� string �Ѿ�����Ԫ�صĴ�С
	std::size_t size() const { return end - begin; }
	// ���� string �ĳ���
	std::size_t length() const { return end - begin + 1; }


private:
	// ��һ��Ԫ������λ��
	char* begin;
	// ��һ��Ԫ������λ��
	char* end;
	// ����Ԫ��
	static std::allocator<char> alloc;
	// �����ڴ沢����������Χ��Ԫ��
	std::pair<char*, char* > alloc_n_copy(const char*, const char*);
	// ���ٹ����Ԫ�ز��ͷ��ڴ�
	void free();
};



#endif // STRING