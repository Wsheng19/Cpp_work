#include<iostream>
using namespace std;

class Triangle
{
public:
	Triangle(int, int, int);
private:
	int a;
	int b;
	int c;
};

Triangle::Triangle(int a, int b, int c)
{
	a = a; b = b; c = c;
	if (a + b > c&&a + c > b&&b + c > a)
	{
		if (a == b && a == c)
			cout << "A equileteral triangle";
		else if (a == b || a == c || b == c)
			cout << "A isosceles triangle";
		else if (a*a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
			cout << "A right triangle";
		else cout << "A triangle";
	}
	else cout << "Not a triangle";
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	Triangle tri(a, b, c);
	system("pause");
}