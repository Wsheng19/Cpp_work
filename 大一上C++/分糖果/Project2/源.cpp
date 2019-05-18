#include<iostream>
using namespace std;
static int a[10];
void fun1() {
	int m = a[9];
	for (int i = 9; i >0; i--)
		a[i] = a[i - 1] / 2 + a[i] / 2;
	a[0] = m / 2 + a[0] / 2;
	for (int i = 0; i < 10; i++)
		if (a[i] % 2 == 1)
			a[i]++;
}
void fun2() {
	int flag = 0, n = 0, p = 1;
	while (p) {
		for (int i = 1; i < 10; i++)
			if (a[i] != a[0]) {
				flag++;
				p = 1;
			}
		if (flag == 0) {
			cout << n << ' ' << a[0];
			p = 0;
		}
		fun1();
		n++;
		flag = 0;
	}
}
int main() {
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	fun2();
	system("pause");
}