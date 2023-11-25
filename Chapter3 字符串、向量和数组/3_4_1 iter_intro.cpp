#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	/*------------------ 3.22 ------------------*/
	// �� test ��һ�θ�Ϊ��д
	string test = "hello world";
	for (auto it = test.begin(); it != test.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it);
	}
	cout << test << endl;
	/*------------------ 3.23 ------------------*/
	// �� vector ��Ԫ�ؾ���Ϊ����
	vector<int> int_list = { 1,2,3,4,5,6,7,8,9,10 };
	for (auto it = int_list.begin(); it != int_list.end(); ++it)
	{
		*it = 2 * (*it);
	}
	for (auto it : int_list)
	{
		cout << it << endl;
	}



	return 0;
}