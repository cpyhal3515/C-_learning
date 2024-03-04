#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<fstream>
#include <functional>
#include "Quote_class.h"
#include "Basket.h"
using namespace std;

// ����Ŀǰ����Ŀ���
#define PROBLEM_15_30


#ifdef  PROBLEM_14_35
#endif



int main()
{
#ifdef  PROBLEM_15_06
    // ���� Quote �Լ� Bulk_quote
    Quote q1("978-7-121-15535-2", 1.2);
    Bulk_quote q2("978-7-121-15535-2", 1.2, 20, 0.8);

    print_total(cout, q1, 32);
    print_total(cout, q2, 32);
#endif


#ifdef PROBLEM_15_26
    Bulk_quote bulk("978-7-121-15535-2", 100, 2, 0.2);    // ���������
    std::cout << std::endl;

    std::cout << "------Bulk_quote bulk1 = bulk------" << std::endl;
    Bulk_quote bulk1 = bulk;
    std::cout << std::endl;

    std::cout << "------Bulk_quote bulk2 = bulk------" << std::endl;
    Bulk_quote bulk2;
    bulk2 = bulk;
    std::cout << std::endl;

    std::cout << "------Bulk_quote bulk3 = std::move(bulk)------" << std::endl;
    Bulk_quote bulk3 = std::move(bulk);
    std::cout << std::endl;

    std::cout << "------Quote quote1 = bulk------" << std::endl;
    Quote quote1 = bulk;
    std::cout << std::endl;

    std::cout << "------Quote quote2 = std::move(bulk)------" << std::endl;
    Quote quote2 = std::move(bulk);
    std::cout << std::endl;
#endif

#ifdef PROBLEM_15_28_29
    cout << "/*---------- ʹ�� Quote ----------*/" << endl;
    vector<Quote> itemVec;
    // ������ 2 ������
    Bulk_quote bulk1("978-7-121-15535-2", 100, 2, 0.9);    // ���������
    // ������ 5 ������
    Bulk_quote bulk2("978-7-121-15535-1", 100, 5, 0.8);    // ���������

    itemVec.push_back(bulk1);
    itemVec.push_back(bulk2);
    print_total(cout, itemVec[0], 4);
    print_total(cout, itemVec[1], 6);
    cout << itemVec[0].net_price(4) + itemVec[1].net_price(6) << endl;

    cout << "/*---------- ʹ�� shared_ptr<Quote> ----------*/" << endl;
    vector<shared_ptr<Quote>> itemVecPtr;
    // ������ 2 ������
    shared_ptr<Bulk_quote> bulk1ptr = make_shared<Bulk_quote>("978-7-121-15535-2", 100, 2, 0.9);
    // ������ 5 ������
    shared_ptr<Bulk_quote> bulk2ptr = make_shared<Bulk_quote>("978-7-121-15535-1", 100, 5, 0.8);

    itemVecPtr.push_back(bulk1ptr);
    itemVecPtr.push_back(bulk2ptr);
    print_total(std::cout, *itemVecPtr[0], 4);
    print_total(std::cout, *itemVecPtr[1], 6);
    std::cout << itemVecPtr[0]->net_price(4) + itemVecPtr[1]->net_price(6)
        << std::endl;

#endif

#ifdef PROBLEM_15_30

    Basket item;
    for (auto i = 0; i < 4; ++i)
        // ������ 2 ������
        item.add_item(Bulk_quote("978-7-121-15535-2", 100, 2, 0.9));
    for (auto i = 0; i < 6; ++i)
        // ������ 5 ������
        item.add_item(Bulk_quote("978-7-121-15535-1", 100, 5, 0.8));
    item.total_receipt(std::cout);


#endif
}