#include<iostream>
#include<iomanip>
#include"month.h"
using namespace std;

int main()
{
	cout << "������Ҫ��ӡ�����µ�������";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "��������ݣ���2010����";
		int year;
		cin >> year;
		cout << "�������·ݣ�1-12��";
		int month;
		cin >> month;
		printMonth(year, month);
		cout << endl;
	}
	system("pause");
}

void printMonth(int year, int month)
{
	printMonthTitle(year, month);
	printMonthBody(year, month);
}