#ifndef STRBLOB
#define STRBLOB

#include<iostream>
#include<string>
#include<vector>
#include<memory>

class StrBlobPtr;
class StrBlob
{
friend class StrBlobPtr;
friend bool operator==(const StrBlob&, const StrBlob&);
friend bool operator!=(const StrBlob&, const StrBlob&);
friend bool operator<(const StrBlob&, const StrBlob&);
friend bool operator<=(const StrBlob&, const StrBlob&);
friend bool operator>(const StrBlob&, const StrBlob&);
friend bool operator>=(const StrBlob&, const StrBlob&);
public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
	// �������캯��
	StrBlob(const StrBlob& orig) : data(std::make_shared<std::vector<std::string>>(*orig.data)) {}
	// ������ֵ�����
	StrBlob& operator=(const StrBlob& orig)  
	{
		data = std::make_shared<std::vector<std::string>>(*orig.data);
		return *this;
	}



	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	// ��Ӻ�ɾ��Ԫ��
	void push_back(const std::string& t) 
	{ 
		data->push_back(t); 
	}
	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}

	//Ԫ�ط���
	std::string& front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}
	std::string& back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	// ȡ����Ԫ�أ������ﲻ��ʵ�� begin �Լ� end����Ϊ StrBlobPtr ��û������
	StrBlobPtr begin();
	// ȡ��ĩԪ��
	StrBlobPtr end();

	// �±������
	std::string& operator[](std::size_t n)
	{
		check(n, "out of range");
		return (*data).at(n);
	}
	// �±������ const �汾
	const std::string& operator[](std::size_t n) const
	{
		check(n, "out of range");
		return (*data).at(n);
	}


private:
	std::shared_ptr<std::vector<std::string>> data;
	//��� data[i] ���Ϸ����׳�һ���쳣
	void check(size_type i, const std::string& msg) const
	{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}

};

/* ---------------------- �������� ---------------------- */
// ��������
bool operator==(const StrBlob& lhs, const StrBlob& rhs) {
	return *(lhs.data) == *(rhs.data);            // ��ָ��� vector ���
}
// ����������
bool operator!=(const StrBlob& lhs, const StrBlob& rhs) {
	return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs) { 
	return *(lhs.data) < *(rhs.data);
}
bool operator>(const StrBlob& lhs, const StrBlob& rhs) {
	return rhs < lhs;
}
bool operator<=(const StrBlob& lhs, const StrBlob& rhs) {
	return !(lhs > rhs);
}
bool operator>=(const StrBlob& lhs, const StrBlob& rhs) {
	return !(lhs < rhs);
}
/* ----------------------------------------------------- */


// �������һ�������ڵ�Ԫ���� StrBlobPtr �׳�һ���쳣
class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr& , const StrBlobPtr& );
	friend bool operator<=(const StrBlobPtr& , const StrBlobPtr& );
	friend bool operator>(const StrBlobPtr& , const StrBlobPtr& );
	friend bool operator>=(const StrBlobPtr& , const StrBlobPtr& );
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	std::string& deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	// �±������ const �汾
	const std::string& operator[](std::size_t n) const
	{
		auto p = check(n, "out of range");
		return (*p)[n];
	}
	// ������ݼ��������ǰ�ã�
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	// ������ݼ�����������ã�
	StrBlobPtr& operator++(int);
	StrBlobPtr& operator--(int);

	// �������������ָ��ֵ�ĸ���
	StrBlobPtr& operator+=(size_t n);
	StrBlobPtr& operator-=(size_t n);
	// +��- ���������ָ��ֵ�ĸ���
	StrBlobPtr operator+(size_t n) const;
	StrBlobPtr operator-(size_t n) const;
private:
	// �����ɹ���check ����һ��ָ�� vector �� shared_ptr
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t i, const std::string& msg) const
	{
		// �ж� vector �Ƿ����
		auto ret = wptr.lock();
		if (!ret)
			throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size() || i < 0)
			throw std::out_of_range(msg);
		return ret;
	}
	std::weak_ptr<std::vector<std::string>> wptr;

	// �������е�ǰ��λ��
	std::size_t curr;

};


// begin and end members for StrBlob
inline
StrBlobPtr
StrBlob::begin()
{
	return StrBlobPtr(*this);
}

inline
StrBlobPtr
StrBlob::end()
{
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
/* ---------------------- �������� ---------------------- */
// ʵ�ֵ����Լ����ȵĺ���
bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		// ���� null ����ָ����ͬԪ��˵�����
		return (!r || lhs.curr == rhs.curr);
	else
		return false; // ���ָ��ͬ�� vector��˵������
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	return lexicographical_compare(l->begin(), l->end(), r->begin(), r->end());
}
bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	return rhs < lhs;
}
bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	return !(lhs > rhs);
}
bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	return !(lhs < rhs);
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}
StrBlobPtr& StrBlobPtr::operator--()
{
	// ��� curr �� 0��������ݼ��������һ����Ч�±�
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

// ���ð汾������/�ݼ������ֵ���Ƿ���ԭֵ
StrBlobPtr& StrBlobPtr::operator++(int) {
	// �˴���������Ч�ԣ�����ǰ�õ�������ʱ����Ҫ���
	StrBlobPtr ret = *this;         // ��¼��ǰ��ֵ
	++*this;        // ��ǰ�ƶ�һ��Ԫ�أ�ǰ��++��Ҫ����������Ч��
	return ret;     // ����֮ǰ��¼��״̬
}
StrBlobPtr& StrBlobPtr::operator--(int) {
	// �˴���������Ч�ԣ�����ǰ�õݼ�����ʱ����Ҫ���
	StrBlobPtr ret = *this;         // ��¼��ǰ��ֵ
	++*this;        // ����ƶ�һ��Ԫ�أ�ǰ��--��Ҫ���ݼ�����Ч��
	return ret;     // ����֮ǰ��¼��״̬
}

StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}
StrBlobPtr& StrBlobPtr::operator-=(size_t n)
{
	curr -= n;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
StrBlobPtr StrBlobPtr::operator+(size_t n) const
{
	StrBlobPtr ret = *this;         // ��¼��ǰ��ֵ
	ret += n;       
	return ret;     // ����֮ǰ��¼��״̬
}
StrBlobPtr StrBlobPtr::operator-(size_t n) const
{
	StrBlobPtr ret = *this;         // ��¼��ǰ��ֵ
	ret -= n;
	return ret;     // ����֮ǰ��¼��״̬
}
/* ----------------------------------------------------- */
#endif // STRBLOB