#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>S
using namespace std;

class Maker
{
	
public:
	Maker(int age)
	{
		this->age = age;
	}
	Maker(const Maker &m)
	{
		cout << "�������캯��" << endl;
	}
//1.��֤�����Ŀ������캯���ܱ�����
//2.ע����ǳ��������

public:
	int age;
};

void test()
{
	vector<Maker> v;
	//��ʵ���ǰ�Maker(10)�������������������ǿ���һ�ݷ���������
	v.push_back(Maker(10));
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

