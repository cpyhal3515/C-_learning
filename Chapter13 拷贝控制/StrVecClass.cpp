#include "StrVecClass.h"
using namespace std;


std::allocator<std::string> StrVec::alloc;

/* ---------------------- �������� ---------------------- */
// ���캯����ʹ�� initializer_list ���й���
StrVec::StrVec(std::initializer_list<std::string> input_list)
{
	auto new_data = alloc_n_copy(input_list.begin(), input_list.end());
	elements = new_data.first;
	first_free = cap = new_data.second;
}
// �������캯��
StrVec::StrVec(const StrVec& orig)
{
	auto new_data = alloc_n_copy(orig.begin(), orig.end());
	elements = new_data.first;
	first_free = cap = new_data.second;

}
// �ƶ����캯��
StrVec::StrVec(StrVec&& orig) noexcept // �ƶ�������Ӧ���׳��κ��쳣
	// ��Ա��ʼ�����ӹ� orig �е���Դ
	: elements(orig.elements), first_free(orig.first_free), cap(orig.cap)
{
	// �� orig �������������״̬
	orig.elements = orig.first_free = orig.cap = nullptr;

}
// ������ֵ�����
StrVec& StrVec::operator=(const StrVec& rhs)
{
	auto new_data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = new_data.first;
	first_free = cap = new_data.second;
	return *this;
}
// �ƶ���ֵ�����
StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
	// ����Ը�ֵ
	if (this != &rhs)
	{
		// �ͷ�����Ԫ��
		free();
		// �� rhs �ӹ���Դ
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		// �� rhs ���ڿ�������״̬
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	
	return *this;
}
// ��������
StrVec::~StrVec()
{
	free();
}
/* ----------------------------------------------------- */


/* ---------------------- ���ܺ��� ---------------------- */
void StrVec::push_back(const string& str)
{
	// ȷ���пռ�������Ԫ��
	chk_n_alloc();
	// �� first_free ָ���Ԫ���й��� str �ĸ���
	alloc.construct(first_free++, str);
}


pair<string*, string* > StrVec::alloc_n_copy(const string* b, const string* e)
{
	// ����ռ䱣�����Ԫ��
	auto data = alloc.allocate(e - b);
	// ��ԭʼ���ݿ������·���Ŀռ���
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements)
	{
		// �������پ�Ԫ��
		for (auto p = first_free; p != elements;)
		{
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate()
{
	// ���䵱ǰ��С�����Ŀռ�
	auto new_cap = (size() == 0) ? 1 : 2 * size();
	// �������ڴ�
	auto new_data = alloc.allocate(new_cap);
	// �����ݴӾ��ڴ��������ڴ�
	auto dest = new_data;
	auto elem = elements;

	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, move(*elem++));
	}

	// �ͷž��ڴ�ռ�
	free();
	// ����Ԫ��
	elements = new_data;
	first_free = dest;
	cap = elements + new_cap;
}
/* ----------------------------------------------------- */