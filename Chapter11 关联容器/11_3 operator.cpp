#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<sstream>
#include<fstream>
using namespace std;

// ����Ŀǰ����Ŀ���
#define PROBLEM_11_33


#ifdef PROBLEM_11_33

// ��������ת��ӳ���
//map<string, string> bulid_map(ifstream& map_file)
unordered_map<string, string> bulid_map(ifstream& map_file)
{
	// ��������ת��ӳ���
	//map<string, string> word_map;
	unordered_map<string, string> word_map;
	string word_key, word_value;
	while (map_file >> word_key && getline(map_file, word_value))
	{
		// �����ת����ϵ��size �� 1 ��
		if (word_value.size() > 1)
			// ��ת����ϵ���뵽 map ��
			word_map.insert({ word_key , word_value.substr(1) });
		else
			throw runtime_error("no rule for" + word_key);
	}
	return word_map;
}
// ���ո�ӳ���ת�������еĵ���
//string transform_sentence(map<string, string> map_rule, string& word)
string transform_sentence(unordered_map<string, string> map_rule, string& word)
{
	// �����Ƿ���ת����ϵ
	auto map_it = map_rule.find(word);
	// ��ת����ϵ�ͽ���ת��
	if (map_it != map_rule.cend())
		return map_it->second;
	else
		return word;
}
// ���ո�ӳ���ת����������
void word_transform(ifstream& map_file, ifstream& origin_file)
{
	auto map_rule = bulid_map(map_file);
	string file_line;
	// ת��һ��������
	while (getline(origin_file, file_line))
	{
		istringstream line_stream(file_line);
		string word;
		while (line_stream >> word)
		{
			cout << transform_sentence(map_rule, word) << " ";
		}
		cout << endl;
	}

	return;
}


#endif


int main()
{

#ifdef PROBLEM_11_16
	// ʹ�� map ��������дһ�����ʽ
	// ��һ��ֵ����һ��Ԫ��
	map<int, int> test_list = { {1,10},{2,20},{3,30},{4,40} };
	for (auto tl = test_list.begin(); tl != test_list.end(); ++tl)
	{
		++tl->second;
	}
	for (auto tl : test_list)
	{
		cout << tl.first << " " << tl.second << endl;
	}
#endif

#ifdef PROBLEM_11_17
	multiset<string> c = { "Hello", "World", "Ni", "Hao" };
	vector<string> v ;

	//copy(v.begin(), v.end(), inserter(c, c.end()));
	//copy(v.begin(), v.end(), back_inserter(c));
	copy(c.begin(), c.end(), inserter(v, v.end()));
	copy(c.begin(), c.end(), back_inserter(v));

#endif

#ifdef  PROBLEM_11_20
	// ��д���ʼ�������ʹ�� insert
	map<string, int> word_list;
	string word;
	ifstream in("./data.txt");
	while (in >> word)
	{
		auto ret = word_list.insert({ word, 1 });
		if (!ret.second)
			++ret.first->second;
	}

	for (auto w : word_list)
	{
		cout << w.first << " : " << w.second << endl;
	}

#endif


#ifdef  PROBLEM_11_23
	// map �м��Ǽ�ͥ��ֵ�Ǻ���
	// ʵ������µļ�ͥ�Լ������м�ͥ������µĺ���
	// Andy andy1 andy2 andy3
	// Andy andy4
	string family_name;
	string child_info;
	multimap<string, string> family_list;
	while (cin >> family_name && getline(cin, child_info))
	{
		istringstream child_name_stream(child_info);
		string child_name_str;
		while (child_name_stream >> child_name_str)
		{
			family_list.insert({family_name, child_name_str});
		}
	}

	for (auto fl : family_list)
	{
		cout << fl.first << " " << fl.second << endl;
	}



#endif

#ifdef  PROBLEM_11_28
	map<string, vector<int>> map_list;
	decltype(map_list.find(" ")) result;
	result = map_list.find(" ");

#endif

#ifdef  PROBLEM_11_31_32
	// find ����Ԫ�ز�ɾ��
	// �����ֵ����ӡ�����б�����ǵ���Ʒ
	multimap<string, string> author_list = { {"aaa", "a"}, {"aaa", "b"}, {"aaa", "c"}, {"bbb", "a"}, {"bbb", "b"}, {"ccc", "c"} };
	string delete_str = "ddd";
	cout << "author_list.size = " << author_list.size() << endl;
	if (author_list.find(delete_str) != author_list.end())
	{
		author_list.erase(delete_str);
	}
	cout << "author_list.size = " << author_list.size() << endl;

	string auther_tmp = " ";
	for (auto auther : author_list)
	{
		if (auther.first != auther_tmp)
		{
			if(auther_tmp != " ")
				cout << endl;
			auther_tmp = auther.first;
			cout << auther_tmp << endl;
			cout << auther.second << " ";
		}
		else
		{
			cout << auther.second << " ";
		}
		
	}

#endif

#ifdef  PROBLEM_11_33
	string map_file_path = "./map_file.txt";
	string origin_file_path = "./origin_file.txt";
	ifstream map_file(map_file_path);
	ifstream origin_file(origin_file_path);
	word_transform(map_file, origin_file);

#endif


	return 0;



}