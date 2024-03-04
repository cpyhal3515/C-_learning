/*--------------- ʹ�� class ������ ---------------*/
#ifndef BASKET_CLASS_H
#define BASKET_CLASS_H

#include<iostream>
#include<string>
#include<set>
#include "Quote_class.h"

// ���� Basket ��
class Basket
{
public:
	// Basket ʹ��Ĭ�ϺϳɵĹ��캯���뿽�����Ƴ�Ա

	void add_item(const Quote& sale)
	{
		item.insert(std::shared_ptr<Quote>(sale.clone()));	// ���������Ķ���
	}
	void add_item(const Quote&& sale)
	{
		item.insert(std::shared_ptr<Quote>(std::move(sale).clone()));	// �ƶ������Ķ���
	}
	// ��ӡÿ������ܼۺ͹���������������ܼ�
	double total_receipt(std::ostream&) const;

private:
	// multiset �õ��ıȽϺ���
	static bool compare(const std::shared_ptr<Quote>& lhs,
		const std::shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> item{ compare };
	
};


#endif // BASKET_CLASS_H