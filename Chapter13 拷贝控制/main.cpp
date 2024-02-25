#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<fstream>
//#include "XClass.h"
//#include "EmployeeClass.h"
//#include "HasPtrClass_val.h"
#include "StrVecClass.h"
#include "StringClass.h"
using namespace std;

// ����Ŀǰ����Ŀ���
#define PROBLEM_13_39_40


#ifdef  PROBLEM_13_14_15_16
class numbered 
{
public:
    numbered() 
    {
        mysn = unique++;
    }
    numbered(const numbered& n)
    {
        mysn = unique++;
    }

    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered& s) 
{
    std::cout << s.mysn << std::endl;
}

#endif

int main()
{
#ifdef  PROBLEM_13_13
    // ��⿽�����Ƴ�Ա�͹��캯����һ���÷����Ķ���һ���򵥵��࣬Ϊ���ඨ����Щ��Ա��ÿ����Ա����ӡ���Լ�������
	X* x = new X;
	delete x;
#endif
  
#ifdef  PROBLEM_13_14_15_16
    // �ٶ� numbered ��һ���࣬����һ��Ĭ�Ϲ��캯����
    // ��Ϊÿ����������һ��Ψһ����ţ���������Ϊ mysn �����ݳ�Ա�С�
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
#endif

#ifdef PROBLEM_13_18
     // ����һ�� Employee �࣬��������Ա��������Ψһ�Ĺ�Ա֤�š�
    Employee member1("Zhang San");
    Employee member2("Li Si");
    cout << "member1 name = " << member1.getname() << " , member1 id = " << member1.get_id() << endl;
    cout << "member2 name = " << member2.getname() << " , member2 id = " << member2.get_id() << endl;

#endif // PROBLEM_13_18

#ifdef PROBLEM_13_31
    vector<HasPtr> vec;
    for (int i = 0; i < 10; ++i)
    {
        string str = "a";
        HasPtr tmp(str, 10-i);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        it->print();
    }

#endif
#ifdef PROBLEM_13_39_40
    // ���� StrVec
    StrVec test = {"a", "b", "c"};
    test.push_back("nihao1");
    test.push_back("nihao2");
    test.push_back("nihao3");

    for (auto it = test.begin(); it != test.end(); ++it)
    {
        cout << *it << endl;
    }

    // ���� String
    vector<String> tmp;
    tmp.push_back("nihao1");
    tmp.push_back("nihao2");
    tmp.push_back("nihao3");
    tmp[2] = tmp[1];
    for (auto it = tmp.begin(); it != tmp.end(); ++it)
    {
        auto beg = it->c_str();

        for (int i = 0; i < it->size(); ++i)
        {
            cout << beg[i];
        }
        cout << endl;
    }
    
#endif // PROBLEM_13_39





}