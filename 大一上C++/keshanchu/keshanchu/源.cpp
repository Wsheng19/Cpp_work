#include<iostream>
using namespace std;
int main()
{
	int a,n, b = 0;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		cin >> a;
		b = 0;
		for (int i = 2; i < a; i++)
			if (a%i == 0) b = 1;
		if (b)
		{
			cout << "是合数" << endl;
			for (int m = 1; m <= a; m++)
				if (a%m == 0)
					cout << m << ' ';
		}
		else cout << "是素数" << endl;

	}
	system("pause");
}