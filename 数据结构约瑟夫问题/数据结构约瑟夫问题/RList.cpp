#include<iostream>
#include"RList.h"

using namespace std;

int main()
{
	cout << "�������������������\n";
	int person_n, number;
	cin >> person_n >> number;
	if (person_n <= 0 || number <= 0) cout << "��������������Ų���Ϊ��";
	else {
		int *p = new int[person_n];
		for (int i = 0; i < person_n; i++)
			p[i] = i + 1;
		RList Josephus(p, person_n);
		cout << "���һ�����е��ǣ�" << Josephus.Josephus(number);
		delete p;
	}
	system("pause");
}