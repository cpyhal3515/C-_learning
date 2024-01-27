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


private:
	std::shared_ptr<std::vector<std::string>> data;
	//��� data[i] ���Ϸ����׳�һ���쳣
	void check(size_type i, const std::string& msg) const
	{
		if (i >= data->size())
			throw std::out_of_range(msg);
	}

};


// �������һ�������ڵ�Ԫ���� StrBlobPtr �׳�һ���쳣
class StrBlobPtr
{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :
		wptr(a.data), curr(sz) {}
	std::string& deref() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	StrBlobPtr& incr()
	{
		// ��� curr �Ѿ���������β��Ͳ��ܵ���
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}



private:
	// �����ɹ���check ����һ��ָ�� vector �� shared_ptr
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t i, const std::string& msg) const
	{
		// �ж� vector �Ƿ����
		auto ret = wptr.lock();
		if (!ret)
			throw std::runtime_error("unbound StrBlobPtr");
		if (i >= ret->size())
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

// ʵ�ֵ����Լ����ȵĺ���
inline
bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		// ���� null ����ָ����ͬԪ��˵�����
		return (!r || lhs.curr == rhs.curr);
	else
		return false; // ���ָ��ͬ�� vector��˵������
}

inline
bool neq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !eq(lhs, rhs);
}

#endif // STRBLOB