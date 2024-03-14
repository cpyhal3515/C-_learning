#ifndef BLOB_CLASS_H
#define BLOB_CLASS_H

#include <iterator>
#include <string>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

// Blob ����Ԫ��������Ҫ�õ�
template <typename>
class BlobPtr;
// operator== �Ķ�������Ҫ�õ�
template <typename>
class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);



template <typename T>
class Blob 
{
    // Blob �Լ� BlobPtr ��Ӧ��ʵ�������Ӧ������ͬ������
    friend class BlobPtr<T>;

    friend bool operator==<T>
        (const Blob<T>&, const Blob<T>&);


public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    // ���캯��
    Blob();
    // ע���������ֵ���һ���������������� It
    template <typename It>
    Blob(It b, It e);
    Blob(T*, std::size_t);

    // ���� BlobPtr �ĵ�һ��Ԫ���Լ����һ��Ԫ��
    BlobPtr<T> begin() 
    { 
        return BlobPtr<T>(*this); 
    }
    BlobPtr<T> end() 
    {
        BlobPtr<T> ret = BlobPtr<T>(*this, data->size());
        return ret;
    }

    // Blob �е�Ԫ�ظ���
    size_type size() const { return data->size(); }
    // Blob �Ƿ�Ϊ��
    bool empty() const { return data->empty(); }

    // �����ɾ��Ԫ��
    void push_back(const T& t) { data->push_back(t); }
    void pop_back();

    // Ԫ�ط���
    T& front();
    T& back();
    T& at(size_type);
    // ��һ�� const ��ʾ�������ص��ǶԳ��������á�
    // �ڶ��� const ��ʾ�ó�Ա���������޸Ķ�����ڲ�״̬��
    const T& front() const;
    const T& back() const;
    const T& at(size_type) const;

    T& operator[](size_type i);
    const T& operator[](size_type i) const;

    void swap(Blob& b) { data.swap(b.data); }

private:
    // ����
    std::shared_ptr<std::vector<T>> data;
    // ��� data[i] �����ھ��׳� msg
    void check(size_type i, const std::string& msg) const;
};


/*------------Blob ��ĳ�Ա����------------*/
// ���캯��
template <typename T>
Blob<T>::Blob(T* p, size_t n) :
    data(new std::vector<T>(p, p + n)) {}

template <typename T>
Blob<T>::Blob() :
    data(new std::vector<T>()) {}

// T ��ʾ class �� typename��It ��ʾ�������� typename
template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) :
    data(new std::vector<T>(b, e)) {}

// ��������Ƿ�Խ��
template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

// Ԫ�س�Ա����
template <typename T>
T& Blob<T>::front()
{
    // ��� vector �ǿյģ��ͻ��׳�������ʾ�ı���
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
const T& Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
const T& Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::at(size_type i)
{
    // ��������Ƿ�Խ��
    check(i, "subscript out of range");
    return (*data)[i];  // ���ض�Ӧ��ֵ
}

template <typename T>
const T&
Blob<T>::at(size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    // ��������Ƿ�Խ��
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T&
Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

// ��������
template <typename T>
std::ostream& operator<<(std::ostream& os, const Blob<T> a)
{
    os << "< ";
    for (size_t i = 0; i < a.size(); ++i)
        os << a[i] << " ";
    os << " >";
    return os;
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    if (rhs.size() != lhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}
/*-----------------------------------*/

template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
class BlobPtr 
{
    friend bool
        operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);

public:
    BlobPtr() : curr(0) {}

    BlobPtr(Blob<T>& a, size_t sz = 0) :
        wptr(a.data), curr(sz) {}

    T& operator[](std::size_t i) 
    {
        std::shared_ptr<std::vector<T> > p = check(i, "subscript out of range");
        return (*p)[i];  // (*p) ��һ�� vector
    }

    const T& operator[](std::size_t i) const 
    {
        std::shared_ptr<std::vector<T> > p = check(i, "subscript out of range");
        return (*p)[i];  // (*p) ��һ�� vector
    }

    T& operator*() const 
    {
        std::shared_ptr<std::vector<T> > p = check(curr, "dereference past end");
        return (*p)[curr]; 
    }

    T* operator->() const 
    { 
        // ��ʵ�ʹ���ί�и������ò����� 
        return &this->operator*();
    }

    // �����Լ��ݼ�
    BlobPtr& operator++();       // ǰ�������
    BlobPtr& operator--();

    BlobPtr operator++(int);     // ���������
    BlobPtr operator--(int);

private:
    // check �ɹ��Ļ��ͷ��� vector ��Ӧ�� shared_ptr
    std::shared_ptr<std::vector<T> >
        check(std::size_t, const std::string&) const;

    // �洢һ�� weak_ptr
    std::weak_ptr<std::vector<T> > wptr;
    std::size_t curr;      // �����е�ǰ��λ��
};

/*------------BlobPtr ��ĳ�Ա����------------*/
// ��������
template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return lhs.wptr.lock().get() == rhs.wptr.lock().get() && lhs.curr == rhs.curr;
}
// ���������
template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    return !(lhs == rhs);
}

// ���
template <typename T>
std::shared_ptr<std::vector<T> >
BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
    std::shared_ptr<std::vector<T> > ret = wptr.lock();   // ��������Ƿ񻹴���
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // ���򣬷���ָ�� vector ��ָ��
}

// ���������
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // ���ﲻ��Ҫ check��check ��ǰ�����������
    BlobPtr ret = *this;   // ���浱ǰֵ
    ++*this;     // ����ǰ�������
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    // ���ﲻ��Ҫ check��check ��ǰ�����������
    BlobPtr ret = *this;  // ���浱ǰֵ
    --*this;     // ����ǰ�������
    return ret;
}

// ǰ�������
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++() {
    // ��� curr �Ѿ�ָ��������ĩβ���Ͳ�����������
    check(curr, "increment past end of BlobPtr");
    ++curr;       // ���� curr ��״̬
    return *this;
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--() {
    // ��� curr �Ѿ�ָ�������Ŀ�ʼ���Ͳ����ټ�����
    --curr;
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}
/*-------------------------------------------*/

#endif //BLOB_CLASS_H
