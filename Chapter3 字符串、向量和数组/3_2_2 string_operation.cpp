#include<iostream>
#include<string>

using namespace std;

int main()
{
	/*------------------ 3.2 ------------------*/
	/*------- 1��һ�ζ���һ���� -------*/
	//string word;
	//while (cin >> word)
	//{
	//	cout << word << endl;
	//}

	/*-------- 2��һ�ζ���һ�� --------*/
	//string line;
	//while (getline(cin, line))
	//{
	//	if (!line.empty())
	//	{
	//		cout << line << endl;
	//	}
	//}

	/*------------------ 3.4 ------------------*/
	/*-------- 1���Ƚ��ַ����Ƿ���� --------*/
	//string str1, str2;
	//cin >> str1;
	//cin >> str2;
	//if (str1 > str2)
	//	cout << str1 << endl;
	//else if (str1 < str2)
	//	cout << str2 << endl;
	//else
	//	cout << str1 << endl;
	
	/*-------- 2���Ƚ��ַ����Ƿ�ȳ� --------*/
	//string str1, str2;
	//cin >> str1;
	//cin >> str2;
	//if (str1.size() == str2.size())
	//	cout << "�����ַ����ȳ���" << endl;
	//else if (str1.size() > str2.size())
	//	cout << str1 << endl;
	//else
	//	cout << str2 << endl;

	/*------------------ 3.5 ------------------*/
	/*-------- 1���ӱ�׼�����ж�ȡ����ַ��� --------*/
	//string word;
	//string result;
	//while (cin >> word)
	//{
	//	result += word;
	//}
	//cout << "���յ�ƴ���ַ���Ϊ��result = " << result << endl;

	/*-------- 2���ÿո�ָ����ַ��� --------*/
	string word;
	string result;
	while (cin >> word)
	{
		result += word +' ';
	}
	cout << "���յ�ƴ���ַ���Ϊ��result = " << result << endl;


	return 0;
}