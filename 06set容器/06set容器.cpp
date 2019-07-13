#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<string>
using namespace std;

void test()
{
	set<int>::iterator it;
	it--;
	it++;
	//it + 2;
	//˫��
	//���ݽṹ�Ƕ�����
}

void printSet(set<int> &s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	set<int> s;
	//Ĭ������������

	s.insert(4);
	s.insert(2);
	s.insert(3);
	s.insert(6);
	s.insert(8);

	printSet(s);
}

struct myfunc
{	
	bool operator()(int v1,int v2) const
	{	// apply operator< to operands
		return (v1 > v2);
	}
};

void printSetmyfunc(set<int,myfunc> &s)
{
	for (set<int,myfunc>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test02()
{
	set<int,myfunc> s;
	

	s.insert(4);
	s.insert(2);
	s.insert(3);
	s.insert(6);
	s.insert(8);

	printSetmyfunc(s);
}

void test03()
{
	set<int, myfunc> s;


	s.insert(4);
	s.insert(2);
	s.insert(3);
	s.insert(6);
	s.insert(8);

	printSetmyfunc(s);

	s.insert(3);//���벻�ᱨ������Ҳ���ᱨ��ֻû�а��ظ������ݲ���

	printSetmyfunc(s);
	pair<set<int,myfunc>::iterator,bool> ret =s.insert(9);
	if (ret.second)
	{
		cout << "����ɹ�" << endl;
	}
	else
	{
		cout << "����ʧ��" << endl;
	}


}

/*
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
1.	count(key);//���Ҽ�key��Ԫ�ظ���
2.	lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
3.	upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

*/

void test04()
{
	set<int> s;
	s.insert(1);
	s.insert(8);
	s.insert(3);
	s.insert(4);
	s.insert(6);
	s.insert(5);
	set<int>::iterator it = s.find(2);

	if (it == s.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҵ�ֵ�ǣ�" << *it << endl;
	}
	cout << "------------------------" << endl;
	it = s.lower_bound(2);
	if (it == s.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҵ�ֵ�ǣ�" << *it << endl;
	}

	it = s.upper_bound(3);
	if (it == s.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҵ�ֵ�ǣ�" << *it << endl;
	}
	cout << "------------------------" << endl;
	pair<set<int>::iterator,set<int>::iterator> ret=s.equal_range(3);
	cout << *(ret.first) << endl;
	cout << *(ret.second) << endl;
}

//�Զ�����������
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

struct Makerfunc
{	// functor for operator<
	bool operator()(const Maker &m1,const Maker &m2) 
	{	// apply operator< to operands
		return m1.age > m2.age;
	}
};

void test05()
{
	set<Maker, Makerfunc> s;
	//Ĭ������������
	s.insert(Maker("aaa1", 10));
	s.insert(Maker("aaa2", 20));
	s.insert(Maker("aaa3", 30));
	s.insert(Maker("aaa4", 40));
	s.insert(Maker("aaa5", 50));

	for (set<Maker, Makerfunc>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << "Name:" << it->name << " Age:" << it->age << endl;
	}
}

//	count(key);//���Ҽ�key��Ԫ�ظ���
void test06()
{
	multiset<int> ms;
	ms.insert(1);
	ms.insert(2);
	ms.insert(2);
	ms.insert(2);
	ms.insert(1);

	int ret=ms.count(2);
	cout << ret << endl;

}
int main()
{
	test06();
	system("pause");
	return EXIT_SUCCESS;
}

