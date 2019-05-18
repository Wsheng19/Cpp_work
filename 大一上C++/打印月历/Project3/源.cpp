#include<iostream>
#include<iomanip>
#include"month.h"
using namespace std;

int main()
{
	cout << "请输入要打印几个月的月历：";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入年份（如2010）：";
		int year;
		cin >> year;
		cout << "请输入月份（1-12）";
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