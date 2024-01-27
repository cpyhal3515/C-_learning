#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<fstream>
#include "StrBlob_class.h"
using namespace std;

// ����Ŀǰ����Ŀ���
#define PROBLEM_12_26




int main()
{
#ifdef  PROBLEM_12_26
	// ʹ�� allocate ʵ���㷨
	int n = 5;
	// ���ٶ�̬���鲢��������
	allocator<string> aloc;
	auto p = aloc.allocate(n);
	auto q = p;

	string s;
	while (cin >> s && q != p + n)
		aloc.construct(q++, s);

	const size_t size = q - p;
	
	// ʹ������
	auto print_idx = p;
	while (print_idx != q)
		cout << *print_idx++ << endl;


	// ���ٶ�̬����
	while (q != p)
		aloc.destroy(--q);
	aloc.deallocate(p, n);





	
#endif





}