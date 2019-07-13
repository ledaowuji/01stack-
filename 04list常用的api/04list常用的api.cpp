#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<vector>
using namespace std;

void printlist(const list<int> &mylist)
{
	for (list<int>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
list<T> lstT;//list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem);//���캯����n��elem����������
list(const list &lst);//�������캯����

*/
void test01()
{
	list<int> mylist(10,6);

	list<int> mylist2(mylist.begin(), mylist.end());

	printlist(mylist);
	printlist(mylist2);
	cout << "--------------" << endl;

	//list�������������
	//sort����Ҫ�������������ʹ�ã�����ʹ���㷨�е�����list�����Լ��ṩ������
	list<int> mylist3;
	for (int i = 0; i < 10; i++)
	{
		mylist3.push_back(i+1);
	}
	mylist3.push_back(2);
	mylist3.push_back(11);
	mylist3.push_back(8);
	
	printlist(mylist3);

	mylist3.sort();

	printlist(mylist3);
}
/*
push_back(elem);//������β������һ��Ԫ��
pop_back();//ɾ�����������һ��Ԫ��
push_front(elem);//��������ͷ����һ��Ԫ��
pop_front();//��������ͷ�Ƴ���һ��Ԫ��
insert(pos,elem);//��posλ�ò�elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�

*/
bool mycompare(int val)
{
	return val > 300;
}

void test02()
{
	list<int> mylist;

	mylist.push_back(10);
	mylist.push_back(20);
	mylist.push_back(30);
	mylist.push_back(40);
	mylist.push_front(100);
	mylist.push_front(200);
	mylist.push_front(300);
	mylist.push_front(400);

	printlist(mylist);


	vector<int> v;
	v.push_back(1000);
	v.push_back(2000);
	v.push_back(3000);

	mylist.insert(mylist.begin(), v.begin(), v.end());
	printlist(mylist);

	mylist.remove(300);

	printlist(mylist);

	mylist.remove_if(mycompare);
	printlist(mylist);
	cout << mylist.size() << endl;
}

void test03()
{
	list<int> mylist;

	mylist.assign(8, 10);

	printlist(mylist);

	cout << mylist.front() << endl;
	cout << mylist.back() << endl;


}
//��ת

bool func(int v1, int v2)
{
	return v1 > v2;
}
void test04()
{

	list<int> mylist;
	mylist.push_back(1);
	mylist.push_back(3);
	mylist.push_back(5);

	printlist(mylist);

	mylist.reverse();
	printlist(mylist);

	mylist.sort();//Ĭ������������
	printlist(mylist);

	mylist.sort(func);
	printlist(mylist);

}

int main()
{
	test04();
	system("pause");
	return EXIT_SUCCESS;
}

