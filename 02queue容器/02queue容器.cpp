#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string>
using namespace std;

//�Ƚ��ȳ�
void test01()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << endl;
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	
	cout << "size:" << q.size() << endl;

}

//2.�洢����
class Maker
{
public:
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

void test02()
{
	queue<Maker> q;
	q.push(Maker("aaa1", 10));
	q.push(Maker("aaa2", 20));
	q.push(Maker("aaa3", 30));

	cout << q.front().name<<" "<<q.front().age << endl;
	cout << q.back().name<<" " <<q.back().age<< endl;
	cout << endl;
	while (!q.empty())
	{
		cout << q.front().name << " " << q.front().age << endl;
		q.pop();
	}

	cout << "size:" << q.size() << endl;
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

