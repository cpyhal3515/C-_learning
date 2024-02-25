#include "StringClass.h"
using namespace std;


std::allocator<char> String::alloc;

/* ---------------------- �������� ---------------------- */
// ���캯����
String::String(const char* s)
{
	char* s_ch = const_cast<char*>(s);
	while (*s_ch)
	{
		++s_ch;
	}

	auto new_data = alloc_n_copy(s, ++s_ch);
	begin = new_data.first;
	end = new_data.second;
}

// �������캯��
String::String(const String& orig)
{
	auto new_data = alloc_n_copy(orig.begin, orig.end);
	begin = new_data.first;
	end = new_data.second;
	cout << "��������" << endl;
}
// �ƶ����캯��
String::String(String&& orig) noexcept // �ƶ�������Ӧ���׳��κ��쳣
// ��Ա��ʼ�����ӹ� orig �е���Դ
	: begin(orig.begin), end(orig.end)
{
	// �� orig �������������״̬
	orig.begin = orig.end = nullptr;
	cout << "�ƶ�����" << endl;
}

// ������ֵ�����
String& String::operator=(const String& rhs)
{
	auto new_data = alloc_n_copy(rhs.begin, rhs.end);
	free();
	begin = new_data.first;
	end = new_data.second;
	cout << "������ֵ" << endl;
	return *this;
}
// �ƶ���ֵ�����
String& String::operator=(String&& rhs) noexcept
{
	// ����Ը�ֵ
	if (this != &rhs)
	{
		// �ͷ�����Ԫ��
		free();
		// �� rhs �ӹ���Դ
		begin = rhs.begin;
		end = rhs.end;
		// �� rhs ���ڿ�������״̬
		rhs.begin = rhs.end = nullptr;
	}
	cout << "�ƶ���ֵ" << endl;
	return *this;
}

// ��������
String::~String()
{
	free();
}
/* ----------------------------------------------------- */


/* ---------------------- ���ܺ��� ---------------------- */

pair<char*, char* > String::alloc_n_copy(const char* b, const char* e)
{
	// ����ռ䱣�����Ԫ��
	auto data = alloc.allocate(e - b);
	// ��ԭʼ���ݿ������·���Ŀռ���
	return { data, uninitialized_copy(b, e, data) };
}

void String::free()
{
	if (begin)
	{
		// �������پ�Ԫ��
		for (auto p = end; p != begin;)
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(begin, end - begin);
	}
}

/* ----------------------------------------------------- */


/* ---------------------- �������� ---------------------- */
bool operator==(const String& lhs, const String& rhs)
{
	return (lhs.size() == rhs.size() && equal(lhs.begin, lhs.end, rhs.begin));
}
bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String& lhs, const String& rhs) {
	// ��׼�⺯�� lexicographical_compare
	// ����һ����Χ[first1, last1) �Ƿ��ֵ���С�ڵڶ�����Χ[first2, last2) 
	return lexicographical_compare(lhs.begin, lhs.end, rhs.begin, rhs.end);
}
bool operator>(const String& lhs, const String& rhs) {
	return rhs < lhs;
}
bool operator<=(const String& lhs, const String& rhs) {
	return !(lhs > rhs);
}
bool operator>=(const String& lhs, const String& rhs) {
	return !(lhs < rhs);
}

/* ----------------------------------------------------- */