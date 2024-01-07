#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
using namespace std;

// ����Ŀǰ����Ŀ���
#define PROBLEM_11_12

int main()
{
#ifdef  PROBLEM_11_7_14
	// map �м��Ǽ�ͥ��ֵ�Ǻ���
	// ʵ������µļ�ͥ�Լ������м�ͥ������µĺ���
	// ���溢�ӵ������Լ���Ӧ������
	// Andy andy1 2023/11/01 andy2 2022/11/01 andy3 2021/11/01
	// Andy andy4 2024/11/01
	string family_name;
	string child_info;
	map<string, vector<pair<string, string>>> family_list;
	while (cin >> family_name && getline(cin, child_info))
	{
		istringstream child_name_stream(child_info);
		string child_name_str;
		string birth_date;
		while (child_name_stream >> child_name_str >> birth_date)
		{
			family_list[family_name].push_back({ child_name_str, birth_date });
		}
	}

	for (auto fl : family_list)
	{
		cout << fl.first << endl;
		for (auto cn : fl.second)
		{
			cout << cn.first << " " << cn.second << endl;
		}
		cout << endl;
	}
	
#endif

#ifdef PROBLEM_11_12
	// ��ÿ��string �� int ����һ�� pair ��
	// pair ������һ�� vector ��
	// aaa 1
	// bbb 2
	// ccc 3
	vector<pair<string, int>> str_int_list;
	string line;

	while (getline(cin, line))
	{
		string str;
		int int_num;
		istringstream lin(line);
		lin >> str;
		lin >> int_num;
		str_int_list.push_back({str, int_num});
	}
	for (auto it : str_int_list)
	{
		cout << it.first << " " << it.second << endl;
	}

#endif







	return 0;



}