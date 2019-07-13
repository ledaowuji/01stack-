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
		cout << "拷贝构造函数" << endl;
	}
//1.保证你对象的拷贝构造函数能被调用
//2.注意深浅拷贝问题

public:
	int age;
};

void test()
{
	vector<Maker> v;
	//其实不是把Maker(10)这个对象放入容器，而是拷贝一份放入容器中
	v.push_back(Maker(10));
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

