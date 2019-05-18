#include<iostream>
using namespace std;

void fun(int v)
{
	int per(1), time(0);
	while (v > 0)
	{
		v -= per;
		if (v > 0) time += per + 1;
		else time += per + v;
		per++;
	}
	cout << time << endl;
}

int main()
{
	int v;
	cin >> v;
	fun(v);
	system("pause");
}