#ifndef VEC_H
#define VEC_H

#include <memory>

template <typename T>
class Vec 
{
public:
    Vec() : elements(0), first_free(0), cap(0) { }
    Vec(const Vec&);                    // �������캯��
    Vec& operator=(const Vec&);         // ������ֵ
    ~Vec();                             // ��������

    // ����Ԫ��
    void push_back(const T&);

    // ��С������
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    // ��ȡԪ��
    T& operator[](size_t n) { return elements[n]; }
    const T& operator[](size_t n) const { return elements[n]; }

    // �������ӿ�
    T* begin() const { return elements; }
    T* end() const { return first_free; }

private:
    static std::allocator<T> alloc;     // ����Ԫ��
    // �� Vec �����Ԫ�صĺ���ʹ�� 
    void chk_n_alloc() { if (first_free == cap) reallocate(); }

  
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();  // ��ȡ����洢�ռ䣬���ҽ�Ԫ�ؿ�����ȥ
    T* elements;        // ָ�������е�һ��Ԫ�ص�ָ��
    T* first_free;      // ָ�������е�һ������Ԫ�ص�ָ�루���һ��Ԫ�ص���һ����
    T* cap;             // ָ������������С��ָ��
};

// ��̬���ݳ�Ա�Ķ���
template <typename T> std::allocator<T> Vec<T>::alloc;

template <typename T>
inline
Vec<T>::~Vec() { free(); }

template <typename T>
inline
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e) 
{
    T* data = alloc.allocate(e - b);
    return std::make_pair(data, std::uninitialized_copy(b, e, data));
}

template <typename T>
inline
Vec<T>::Vec(const Vec& s) 
{
    // ���� copy �������� s ����ͬ������Ԫ�� 
    std::pair<T*, T*> newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
inline
void Vec<T>::free() 
{
    // ���෴��˳�����پɵ�Ԫ��
    for (T* p = first_free; p != elements; /* empty */)
        alloc.destroy(--p);     

    // �����ڿ�ָ���ϵ��� Deallocate
    if (elements)
        alloc.deallocate(elements, cap - elements);
}

template <typename T>
inline
Vec<T>& Vec<T>::operator=(const Vec& rhs) 
{
    // ���� copy �������� RHS ����ͬ������Ԫ�� 
    std::pair<T*, T*> data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
inline
void Vec<T>::reallocate() 
{
    // Ϊ�����ڵ�ǰ��С��Ԫ�ط���ռ� 
    size_t newcapacity = size() ? 2 * size() : 2;

    // �����¿ռ�
    T* first = alloc.allocate(newcapacity);
    T* dest = first;
    T* elem = elements;

    // ����Ԫ��
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, *elem++);
    free();     // ���Ԫ���ƶ����ͷžɿռ� 

    // �������ǵ����ݽṹ��ָ���µ�Ԫ�� 
    elements = first;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
inline
void Vec<T>::push_back(const T& s) 
{
    chk_n_alloc();      // ��Ҫʱ���·���ռ�
    // �� s ���� first_free ��ǰָ���Ԫ�أ�֮����� first_free
    alloc.construct(first_free++, s);
}

#endif //VEC_H
