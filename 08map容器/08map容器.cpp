#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
#include<string>
using namespace std;

void test()
{
	//���ݽṹ�Ƕ�����
	map<int, int>::iterator it;
	it++;
	it--;
	//it + 2;
	//˫��


}

void printMap(map<int, string> &mymap)
{
	for (map<int, string>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

void test01()
{
	map<int, string> mymap;

	//1.��һ�ֲ�������
	mymap.insert(pair<int, string>(3, "aaa"));

	//2.�ڶ��ֲ�������
	mymap.insert(make_pair(6,"ddd"));

	//3.�����ֲ�������
	mymap.insert(map<int, string>::value_type(2, "bbb"));

	//4.�����ֲ�������
	mymap[4] = "ccc";

	printMap(mymap);

	cout << mymap.size() << endl;
	mymap[4] = "666";
	cout << mymap[4] << endl;

	cout << mymap.size() << endl;

	//map�������Լ�ֵΪ��������Ҫ�м�ֵ

}

/*
find(key);//���Ҽ�key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ�����map.end();
count(keyElem);//����������keyΪkeyElem�Ķ����������map��˵��Ҫô��0��Ҫô��1����multimap��˵��ֵ���ܴ���1��
lower_bound(keyElem);//���ص�һ��key>=keyElemԪ�صĵ�������
upper_bound(keyElem);//���ص�һ��key>keyElemԪ�صĵ�������
equal_range(keyElem);//����������key��keyElem��ȵ������޵�������������

*/
void test02()
{
	map<int, string> mymap;
	mymap[1] = "aaa1";
	mymap[2] = "aaa2";
	mymap[3] = "aaa3";
	mymap[4] = "aaa4";
	mymap[5] = "aaa5";
	map<int,string>::iterator it=mymap.find(30);
	if (it == mymap.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�" << endl;
		cout << it->first << " " << it->second << endl;
	}

	multimap<int, string> mumap;
	mumap.insert(make_pair(1, "aa"));
	mumap.insert(make_pair(2, "aa"));
	mumap.insert(make_pair(2, "aa"));
	mumap.insert(make_pair(2, "aa"));
	mumap.insert(make_pair(1, "aa"));

	cout << mumap.count(2) << endl;

	it = mymap.lower_bound(8);
	if (it == mymap.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�" << endl;
		cout << it->first << " " << it->second << endl;
	}

	it = mymap.upper_bound(3);
	if (it == mymap.end())
	{
		cout << "����ʧ��" << endl;
	}
	else
	{
		cout << "���ҳɹ�" << endl;
		cout << it->first << " " << it->second << endl;
	}
	cout << "-------------------" << endl;
	//��������Ԫ�صĵ�������Ԫ�صĶ���
	pair<map<int,string>::iterator,map<int,string>::iterator> ret=mymap.equal_range(3);
	if (ret.first != mymap.end())
	{
		cout << "key:" << ret.first->first << " value:" << ret.first->second << endl;
	}
	if (ret.second != mymap.end())
	{
		cout << "key:" << ret.second->first << " value:" << ret.second->second << endl;
	}
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

