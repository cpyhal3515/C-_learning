#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	/*------------------ 3.16 ------------------*/
	// ����������Ĵ��ȴ���һ�� vector��֮�� vector �е�Ԫ�ظ�д��
	// ��д����ʽ
	vector<string> word_list;
	string word_tmp;
	while (cin >> word_tmp)
	{
		word_list.push_back(word_tmp);
	}
	for (auto &item : word_list)
	{
		for (auto &ch : item)
		{
			ch = toupper(ch);
		}
	}
	for (auto item : word_list)
	{
		cout << item << endl;
	}


	/*------------------ 3.20 ------------------*/
	// input 1 2 3 4 5 6 7 8 9 10
	int tmp;
	vector<int> int_list;
	while (cin >> tmp)
	{
		int_list.push_back(tmp);
	}
	 // ���ڵ�Ԫ�����
	for (decltype(int_list.size()) i = 0; i < int_list.size()/2; i++)
	{
		cout << int_list[2*i] + int_list[2*i + 1] << endl;
	}
	 // ��βԪ�����
	for (decltype(int_list.size()) i = 0; i < int_list.size() / 2; i++)
	{
		cout << int_list[i] + int_list[int_list.size() - 1 - i] << endl;
	}


	return 0;
}