#include<iostream>
#include<vector>
using namespace std;

// ����Ŀǰ����Ŀ���
#define PROBLEM_5_23_24_25

int main()
{
	#ifdef PROBLEM_5_23_24_25
	/* ---------------- 5.23 5.24 5.25 ---------------- */
	// �����쳣

	int num1, num2;
	cout << "Please input two num, num1 / num2" << endl;
	while (cin >> num1 >> num2)
	{
		try
		{
			if (num2 == 0)
			{
				throw runtime_error("num2 cannot be 0!");
			}

			cout << num1 / num2 << endl;
		}
		catch (runtime_error err)
		{
			cout << err.what() << endl;
			cout << "Try again? Enter y or n" << endl;
			string str;
			cin >> str;
			if (!cin || str == "n")
				break;
		}
	}
	
#endif


	return 0;
}