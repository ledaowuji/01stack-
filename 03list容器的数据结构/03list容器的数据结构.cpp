#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

void test()
{
	list<int> mylist;

	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
	}

	//֤����ѭ����  vs 2015 2017   _Myhead()
	list<int>::_Nodeptr node = mylist._Myhead->_Next;//��ȡͷ�ڵ����һ���ڵ�
	for (int i = 0; i < mylist._Mysize * 2;i++)//2015 2017 _Mysize()
	{
		cout << "node:" << node->_Myval << endl;//��ȡ����
		node = node->_Next;
		//����ͷ�ڵ�
		if (node == mylist._Myhead)
		{
			node = node->_Next;
		}

	}

	//֤����˫��
	list<int>::iterator it;
	it++;
	it--;

	//it + 2;�������

}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

