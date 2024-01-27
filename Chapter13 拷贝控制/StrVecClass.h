#ifndef STRVEC
#define STRVEC
// ����ģ��Ϊ string �� vector ���� 
#include<iostream>
#include<string>
#include<vector>
#include<memory>
class StrVec
{
public:
	// ���캯��
	StrVec() : 
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	// ʹ�� initializer_list ���й���
	StrVec(std::initializer_list<std::string>);

	// �������캯��
	StrVec(const StrVec&);
	// �ƶ����캯��
	StrVec(StrVec&&) noexcept;
	// ������ֵ�����
	StrVec& operator=(const StrVec&);
	// �ƶ���ֵ�����
	StrVec& operator=(StrVec&& rhs) noexcept;

	// ��������
	~StrVec();

	// ��Ԫ�ؼ��� vector
	void push_back(const std::string&);
	// ���� vector �Ѿ�����Ԫ�صĴ�С
	std::size_t size() const { return first_free - elements; }
	// ���� vector ������
	std::size_t capacity() const { return cap - elements; }
	// ������ʼԪ�ص�λ��
	std::string* begin() const { return elements; }
	// ������ֹԪ�ص�λ��
	std::string* end() const { return first_free; }
	

private:
	// ��һ��Ԫ������λ��
	std::string* elements;
	// ��һ����Ԫ������λ��
	std::string* first_free;
	// ָʾ���� vector ���������Ԫ�ص�λ��
	std::string* cap;
	// ����Ԫ��
	static std::allocator<std::string> alloc;
	// ��֤��������Ԫ�صĿռ�
	void chk_n_alloc()
	{
		if (size() == capacity())
		{
			reallocate();
		}
	}
	// �����ڴ沢����������Χ��Ԫ��
	std::pair<std::string* , std::string* > alloc_n_copy(const std::string* , const std::string* );
	// ���ٹ����Ԫ�ز��ͷ��ڴ�
	void free();
	// ���ڴ�����ʱΪ StrVec �������ڴ�
	void reallocate();
};



#endif // STRVEC