#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<list>
#include<string>
#include<ctime>
#include<vector>
using namespace std;

//����:��Ա�������ݣ������ɾ��Ƶ�ʸߣ�
//��Ա�Ŷӽ�����ݣ���ȡ���ݴ����Ա���˴�

//������Ա
class Student
{
public:
	string name;
};
//������Ա
void setStudent(queue<Student> &que,int num)
{
	string setName = "ABCDEFGHIJK";
	int sum = rand() % 10;
	for (int i = 0; i < sum; i++)
	{
		Student stu;

		char buf[64] = { 0 };
		sprintf(buf, "%d", num);
		string s(buf);//ת������
		stu.name = "��";
		stu.name += s;
		stu.name += "��";
		stu.name += setName[i];//��1��A

		que.push(stu);//����Ա��������

	}
}

//mylist�ǵ��� que��Ҫ������ݵ���Ա Vpush�Ǵ洢�����ݵ���Ա
int Pushlist(list<Student> &mylist, queue<Student> &que, vector<Student> &Vpush)
{
	int pushnum = 0;//��¼ÿ�������ݵ���Ա����

	while (!que.empty())//�ж�ÿ���Ƿ������Ŷӽ������
	{
		if (mylist.size() >= 15)
		{
			break;
		}

		Student s = que.front();//��ȡԪ��
		Vpush.push_back(s);//�ѽ�����ݵ���Ա�洢��vector������

		mylist.push_back(s);//��Ա�������

		que.pop();//�Ƴ���ͷ��Ա


		pushnum++;


	}

	return pushnum;
}

//������
int Poplist(list<Student> &mylist, vector<Student> &Vpop,int pos)
{
	int popnum = 0;

	if (pos == 17)//��������17��ʱ�����е��˶�������
	{
		while (!mylist.empty())//�жϵ����Ƿ�����
		{
			Student s = mylist.front();
			Vpop.push_back(s);//��¼�����ݵ���Ա

			mylist.pop_front();//��Ա������

			popnum++;

		}
	}

	int num = rand() % 5;
	if (num == 0)//��ʾû�˳�����
	{
		return popnum;
	}

	//����������ʱ�����������ڵ��ڳ����ݵ�����
	if (mylist.size() > 0 && mylist.size() >= num)
	{
		for (int i = 0; i < num; i++)
		{
			Student s = mylist.front();
			Vpop.push_back(s);//��¼�����ݵ���Ա

			mylist.pop_front();//��Ա������

			popnum++;
		}
	}

	return popnum;

}

void printVector(vector<Student> &vec)
{
	for (vector<Student>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << (*it).name << endl;
	}
	cout << endl;
}

void test()
{
	//�������
	srand((unsigned int)time(NULL));
	//��������
	list<Student> mylist;

	//��¼������ݵ�������
	int PushNum = 0;
	//��¼�����ݵ�������
	int PopNum = 0;
	//�洢������ݵ���Ա
	vector<Student> Vpush;
	//�洢�����ݵ���Ա
	vector<Student> Vpop;



	for (int i = 1; i < 18; i++)//��������
	{
		//������Ա
		queue<Student> que;
		setStudent(que,i);

		//�����������15��
		if (mylist.size() <= 15)
		{
			//��������¼���17��ͽ���������17�㲻��Ҫ�������
			if (i < 17)
			{
				//�����ݣ���Ҫ��¼�����ݵ���Ա����������ͨ������ֵ����ȡ
				//��¼�����ݵ���Ա���������԰���Ա��������
				PushNum += Pushlist(mylist, que, Vpush);

			}
		}

		//���������˲��ܳ�����
		if (mylist.size()>0)
		{
			if (i > 1)//��һ��û���˳�����
			{
				//������
				PopNum += Poplist(mylist, Vpop,i);
			}
		}

	}

	//��ӡ�����ݵ���Ա����
	printVector(Vpush);

	//��ӡ�����ݵ���Ա����
	printVector(Vpop);

	cout << "�������˴�:" << PushNum << " �������˴�:" << PopNum << endl;
}


int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

