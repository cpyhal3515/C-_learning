#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<fstream>
#include <functional>
#include "my_sales_item_class.h"
#include "StrBlob_class.h"
#include "StrVecClass.h"
#include "StringClass.h"
using namespace std;

// ����Ŀǰ����Ŀ���
#define PROBLEM_14_44


#ifdef  PROBLEM_14_35
class GetInput
{
public:
    GetInput(istream& in = cin) : is(in){}
    string operator()() 
    { 
        string str;
        getline(is, str);
        return is ? str : string();
    }

private:
    istream& is; // ����д���Ŀ����

};
#endif


#ifdef  PROBLEM_14_38
class LenJudge
{
public:
    LenJudge(int len_) :len(len_) {};
    bool operator()(const string& str) const 
    {
        return str.size() == len;
    }
private:
    int len;
};

#endif

#ifdef  PROBLEM_14_44
// ��ͨ����
int add(int i, int j)
{
    return i + j;
}
// lambda�������һ��δ�����ĺ���������
auto mod = [](int i, int j) { return i % j; };
// ����������
struct divide
{
    int operator() (int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

#endif
int main()
{
#ifdef  PROBLEM_14_2
    // �������ݣ�978-7-121-15535-2 200 99.9
    // ��һ��������Ĳ������� 200 99.9 978-7-121-15535-2
    //Sales_data data_test;
    //cin >> data_test;
    //cout << data_test << endl;

    Sales_data b1("978-7-121-15535-2", 1, 97.9);
    Sales_data b2("978-7-121-15535-2", 1, 99.9);

    std::cout << b1 + b2 << std::endl;
    b1 += b2;
    std::cout << b1 << std::endl;
#endif

#ifdef  PROBLEM_14_18
    StrBlob b1 = { "a", "an", "the" };
    StrBlob b2 = { "a", "an", "the" };
    StrBlob b3 = { "a", "an", "the", "haha" };
    // StrBlob ��������� != �ĵ���
    if (b1 == b2)
    {
        // StrBlobPtr ��������� != �ĵ���
        for (StrBlobPtr iter = b1.begin(); iter != b1.end(); ++iter)
            cout << iter.deref() << " ";
    }
    cout << endl;

    std::cout << "b1 > b2 : " << (b1 > b2) << std::endl;
    std::cout << "b1 < b3 :" << (b1 < b3) << std::endl;
    std::cout << "b1 >= b3 :" << (b1 >= b3) << std::endl;
    std::cout << "b2 <= b3 :" << (b2 <= b3) << std::endl;

    StrVec con_vec_list_1{ "c++", "primer", "5th" };
    //StrVec con_vec_list_2{ "c++", "primer", "5th" };
    StrVec con_vec_list_2{ "c++", "primer", "4th" };
    if (con_vec_list_1 == con_vec_list_2)
    {
        cout << "con_vec_list_1 == con_vec_list_2" << endl;
    }
    else
    {
        cout << "con_vec_list_1 != con_vec_list_2" << endl;
    }
    StrVec vec_list{ "c++", "primer", "5th", "lippman" };
    std::cout << "vec_list > con_vec_list_1 : " << (vec_list > con_vec_list_1) << std::endl;
    std::cout << "vec_list < con_vec_list_1 :" << (vec_list < con_vec_list_1) << std::endl;
    std::cout << "con_vec_list_2 < vec_list :" << (con_vec_list_2 < vec_list) << std::endl;
    std::cout << "con_vec_list_2 >= con_vec_list_1 :" << (con_vec_list_2 >= con_vec_list_1) << std::endl;

    String A("Ni Hao");
    //String B("Ni Hao");
    String B("Ni Hao Ma");
    if (A == B)
    {
        cout << "A == B" << endl;
    }
    else
    {
        cout << "A != B" << endl;
    }

    String s1("One"), s2("Oneone");
    String s3(s2);
    if (s1 < s2)
        cout << "s1 < s2" << endl;
    else
        cout << "s1 >= s2 " << endl;
    if (s3 >= s2)
        cout << "s3 >= s2" << endl;
    else
        cout << "s3 < s2 " << endl;

#endif

#ifdef  PROBLEM_14_23
    StrVec con_vec_list_1 = { "c++", "primer", "5th" };
    for (auto iter = con_vec_list_1.begin(); iter != con_vec_list_1.end(); ++iter)
    {
        cout << *iter << endl;
    }


#endif

#ifdef  PROBLEM_14_26

    // ���� StrBlob
    StrBlob b1 = { "a", "an", "the" };
    for (int i = 0; i < b1.size(); ++i)
    {
        cout << b1[i] << " ";
    }
    cout << endl;
    b1[1] = "haha";
    for (int i = 0; i < b1.size(); ++i)
    {
        cout << b1[i] << " ";
    }
    cout << endl;


    // ���� StrVec
    StrVec con_vec_list_1{ "c++", "primer", "5th" };
    cout << con_vec_list_1[0] << endl;

    // ���� String
    String s1("One");
    cout << s1[2] << endl;
#endif

#ifdef  PROBLEM_14_28
    StrBlob b1 = { "a", "an", "the" };
    StrBlobPtr itr(b1);
    itr += 1;
    cout << itr.deref() << endl;
#endif

#ifdef  PROBLEM_14_35
    // Welcome To CPlusPlus
    GetInput getInput;
    cout << getInput() << endl;
#endif

#ifdef  PROBLEM_14_38
    int len = 3;
    LenJudge lenjudge(len);
    vector<string> svec = {"haha", "ni", "hao", "hello", "world"};
    std::cout << "len : " << len << ", cnt : "
        << std::count_if(svec.begin(), svec.end(), lenjudge)
        << std::endl;
#endif

#ifdef  PROBLEM_14_42
    // ͳ�ƴ��� 1024 ��ֵ�ж��ٸ�
    // _1 ��һ��ռλ���������¿ɵ��ö���ĵ�һ��������
    // ��std::count_if��ivec��ÿ��Ԫ���ϵ�������ɵ��ö���ʱ��
    // ÿ��Ԫ�ض�����Ϊ��һ����������ռλ��_1���ڵ�λ�ã���
    // ��1024����Ϊstd::greater<int>�ĵڶ��������̶������ġ�
    // �����bind ʵ�����ǰ� greater<int>() ���˫��������ת��Ϊһ��������������
    // �̶��ڶ�������Ϊ1024��
    // ����ÿ�ε�������µĵ���������ʱ����ʵ�������ڱȽ������е�ÿ��Ԫ�أ���Ϊ��һ���������Ƿ����1024��
    vector<int> ivec{ 1000, 2000, 3000, 4000, 5000 };
    cout << count_if(ivec.begin(), ivec.end(),
        bind(std::greater<int>(), placeholders::_1, 1024)) << endl;

    // �ҵ���һ�������� pooth ���ַ���
    vector<string> svec{ "pooth", "pooth", "abc", "pooth" };
    cout << *find_if(svec.begin(), svec.end(),
        bind(not_equal_to<string>(), placeholders::_1, "pooth"))
        << endl;

    // �����е�ֵ���� 2
    transform(ivec.begin(), ivec.end(), ivec.begin(),
        std::bind(std::multiplies<int>(), placeholders::_1, 2));
    for (const auto& i : ivec)
        cout << i << " ";
#endif

#ifdef  PROBLEM_14_44
    // �о��˿ɵ��ö������Ԫ�������Ӧ��ϵ�ı��
    // ���пɵ��ö��󶼱���������� int������һ�� int
    // ���е�Ԫ�ؿ����Ǻ���ָ�롢����������� lambda
    map<string, function<int(int, int)>> binops =
    {
        {"+", add},
        {"-", minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j) {return i * j; }},
        {"%", mod}

    };
    cout << binops["+"](1, 2) << endl;
    cout << binops["-"](1, 2) << endl;
    cout << binops["/"](1, 2) << endl;
    cout << binops["*"](1, 2) << endl;
    cout << binops["%"](1, 2) << endl;


#endif
}