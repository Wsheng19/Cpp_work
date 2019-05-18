#include<iostream>
#include"RList.h"

using namespace std;

int main()
{
	cout << "请依次输入人数和序号\n";
	int person_n, number;
	cin >> person_n >> number;
	if (person_n <= 0 || number <= 0) cout << "输入人数或者序号不能为负";
	else {
		int *p = new int[person_n];
		for (int i = 0; i < person_n; i++)
			p[i] = i + 1;
		RList Josephus(p, person_n);
		cout << "最后一个出列的是：" << Josephus.Josephus(number);
		delete p;
	}
	system("pause");
}