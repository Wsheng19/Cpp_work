#include<iostream>
#include"RList.h"

using namespace std;

int main()
{
	int person_n, number;
	cin >> person_n >> number;
	int *p = new int[person_n];
	for (int i = 0; i < person_n; i++)
		p[i] = i + 1;
	RList Josephus(p, person_n);
	Josephus.PrintList();
	cout << Josephus.Josephus(person_n, number);
	system("pause");
}