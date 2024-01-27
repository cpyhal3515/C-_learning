#ifndef TEXTQUERY
#define TEXTQUERY

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
#include<memory>

// ע�⣺���� std ���ܻᱨ���﷨����ȱ�� ";" �ȵ�

// TextQuery �õ� QueryResult���������Ҫ��������
class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	// ���캯��
	// ע�⣺����Ҫ new һ��ռ���ܸ� context_line ��ֵ������ᱨ��
	TextQuery(std::ifstream& infile) : context_line(new std::vector<std::string>)
	{
		std::string lin;
		// ���ж�������
		while (getline(infile, lin))
		{
			context_line->push_back(lin);
			// �����к�
			int n = context_line->size() - 1;
			std::istringstream in(lin);
			std::string wd;
			// ������ʶ���
			while (in >> wd)
			{
				// ���ҵ��� wd �� word_line_num_mp ���ֵ����
				auto &word_set_idx = word_line_num_mp[wd];
				// û�г��ֹ����½�һ�� set
				if (word_set_idx == nullptr)
				{
					word_set_idx.reset(new std::set<line_no>);
				}
				word_set_idx->insert(n);
			}

		}


	};


	// ������ѯ����
	QueryResult query(std::string&);



private:
	// �洢�����ı�
	std::shared_ptr<std::vector<std::string>> context_line;
	// �洢����->�кţ�set����ӳ���ϵ
	std::map<std::string, 
		std::shared_ptr<std::set<line_no>>> word_line_num_mp;


};



class QueryResult
{
	// ����ӡ��������Ϊ��Ԫ
	friend std::ostream& print(std::ostream& stream, QueryResult& qr);
	using line_no = std::vector<std::string>::size_type;
public:
	// ���캯��
	QueryResult(std::string wd, std::shared_ptr<std::set<line_no>> wdln, std::shared_ptr<std::vector<std::string>> ct) :
		word(wd), word_line_number(wdln), context(ct) {}
	
	
private:
	// ��Ҫ��ѯ�ĵ���
	std::string word;
	// ��Ҫ��ѯ�ĵ��ʶ�Ӧ�� line �� set
	std::shared_ptr<std::set<line_no>> word_line_number;
	// �����ı�
	std::shared_ptr<std::vector<std::string>> context;

};

// ���ʲ�ѯ����
inline
QueryResult 
TextQuery::query(std::string& s)
{
	// ����һ����̬ set ��ʾû������
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	// ���� s
	auto find_it = word_line_num_mp.find(s);
	if (find_it == word_line_num_mp.end())
		return QueryResult(s, nodata, context_line);
	else
		return QueryResult(s, word_line_num_mp[s], context_line);
}

// ��ӡ����
std::ostream& print(std::ostream& stream, QueryResult& qr)
{

	stream << "This word appears " << (qr.word_line_number)->size() << " times" << std::endl;

	for (auto it = (qr.word_line_number)->begin(); it != (qr.word_line_number)->end(); ++it)
	{
		stream << "(line num = " << *it + 1 << ") : " << (*(qr.context))[*it] << std::endl;
	}


	return stream;
}


#endif // TEXTQUERY