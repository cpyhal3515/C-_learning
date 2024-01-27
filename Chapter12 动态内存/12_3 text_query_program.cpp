#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<fstream>
#include "TextQuery_class.h"
using namespace std;

void run_queries(ifstream& infile)
{
	// infile ������Ҫ������ļ�
	TextQuery tq(infile); // �����ļ���������ѯ map

	while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		// �������ļ�β���û������� 'q' ʱѭ����ֹ
		if (!(cin >> s) || s == "q") break;
		QueryResult qres = tq.query(s);
		// ָ���ѯ����ӡ���
		print(cout, qres) << endl;
	}

}

int main()
{
	ifstream file_in("./storyDataFile");
	run_queries(file_in);

}