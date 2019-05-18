#include<iostream>
using namespace std;
int main() {
	for (int i = 100; i < 1000; i++) {
		int a = i / 100;
		int b = (i - a * 100) / 10;
		int c = i - a * 100 - b * 10;
		if (i == a * a*a + b * b*b + c * c*c)
			cout << i << ' ';
	}
	system("pause");
}