#ifndef EMPLOYEE
#define EMPLOYEE

#include<iostream>
#include<string>
#include<vector>
#include<memory>
// ����һ�� Employee �࣬��������Ա��������Ψһ�Ĺ�Ա֤�š�
// Ϊ����ඨ��Ĭ�Ϲ��캯�����Լ�����һ����ʾ��Ա������ string �Ĺ��캯����
// ÿ�����캯��Ӧ��ͨ������һ�� static ���ݳ�Ա������һ��Ψһ��֤��
class Employee
{
public:
	Employee();
	Employee(const std::string&);
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;
	std::string getname() { return name; }
	int get_id() { return id; }
	
private:
	std::string name;
	int id;
	static int id_cnt;
};

// ע��������Ҫ��������ж���
int Employee::id_cnt = 0;

Employee::Employee()
{
	++id_cnt;
}
Employee::Employee(const std::string& _name)
{
	name = _name;
	id = id_cnt++;
}

#endif // EMPLOYEE