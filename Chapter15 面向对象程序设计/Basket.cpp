#include "Basket.h"
using namespace std;



/*------------Basket ���Ա------------*/
double Basket::total_receipt(ostream& os) const
{
	double sum = 0.0;	// ����ʵʱ��������ܼ۸�
	// iter ָ�� ISBN ��ͬ��һ��Ԫ���еĵ�һ��
	// upper_bound ����һ��β�������
	for (auto iter = item.cbegin(); iter != item.cend(); iter = item.upper_bound(*iter))
	{
		sum += print_total(os, **iter, item.count(*iter));
	}
	os << "Total Sale: " << sum << endl;	// ��ӡ���յļ۸�
	return sum;
}
/*-----------------------------------------*/