#include<iostream>
using namespace std;

int main()
{
	int a, flag(0);
	cin >> a;
	for (int i = 2; i < a; i++)
		if (a%i == 0) flag = 1;
	if (flag==1)
		for (int i = 1; i <= a; i++)
		{
			if (i != a && a%i == 0) cout << i << ' ';
			else if (i == a) cout << i;
		}
	else cout << "ËØÊý";
	system("pause");
}