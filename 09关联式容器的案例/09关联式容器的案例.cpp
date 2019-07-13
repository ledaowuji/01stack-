#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;
//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
//ͨ��Multimap������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ

#define SALE_DEPATMENT 1 //���۲���
#define DEVELOP_DEPATMENT 2 //�з�����
#define FINACIAL_DEPATMENT 3 //������

//����Ա��
class Woker
{
public:
	string name;
	int age;
	int mSalary;
};

//����Ա��
void CreateWoker(vector<Woker> &vWoker)
{
	srand((unsigned int)time(NULL));
	string setName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Woker woker;
		woker.name = "Ա��";
		woker.name += setName[i];
		woker.age = rand() % 20 + 20;
		woker.mSalary = rand() % 10000 + 10000;
		vWoker.push_back(woker);
	}

}
//Ա������
void WokerByGroup(vector<Woker> &vWoker, multimap<int, Woker> &mWoker)
{

	//����Ա��
	for (vector<Woker>::iterator it = vWoker.begin(); it != vWoker.end(); ++it)
	{
		int dexid = rand() % 3 + 1;
		//Ա������
		mWoker.insert(make_pair(dexid, *it));
	}

}

void myGroup(multimap<int, Woker> &mWoker, int depId)
{
	/*
	1 2
	2 1
	3 2
	*/
	/*
	 key value
	 1    ....
	 1    .....
	 2    .....
	 3    .....
	 3    .....
	*/
	//���Ҳ������ж��ٸ���
	multimap<int, Woker>::iterator it=mWoker.find(depId);
	int mcount = mWoker.count(depId);
	int index = 0;
	for (; it != mWoker.end()&& index<mcount; ++it,++index)
	{
		cout << "Name:" << it->second.name << " age:" << it->second.age << " Salary:" << it->second.mSalary << endl;
	}

}
//��ӡ�����Ա����Ϣ
void printWoker(multimap<int, Woker> &mWoker)
{
	cout << "���۲���Ա����Ϣ����:" << endl;
	myGroup(mWoker, SALE_DEPATMENT);

	cout << "�з�����Ա����Ϣ����:" << endl;
	myGroup(mWoker, DEVELOP_DEPATMENT);

	cout << "������Ա����Ϣ����:" << endl;
	myGroup(mWoker, FINACIAL_DEPATMENT);
}


void test()
{
	vector<Woker> vWoker;//����δ�����Ա����Ϣ

	multimap<int, Woker> mWoker;//���������Ա����Ϣ

	//����Ա��
	CreateWoker(vWoker);

	//����
	WokerByGroup(vWoker, mWoker);

	//��ӡ
	printWoker(mWoker);
}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

