#include<iostream>
using namespace std;
int main()
{
	int a, b, t = 1;
	cin >> a >> b;
	for (int i = (a<b)?a:b; i >1; i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			t = i;
			break;
		}
	}
	cout << t << ' ';
	system("pause");
}