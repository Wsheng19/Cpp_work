#include<iostream>
using namespace std;
const double Pi = 3.14;

class Cirle
{
public:
	void Func1(double);
	void Func2(double);
private:
	double Radius;
};

void Cirle::Func1(double Radius)
{
	Radius = Radius;
	cout << "周长" << 2 * Pi*Radius << ' ';
}

void Cirle::Func2(double Radius)
{
	Radius = Radius;
	cout << "面积" << Pi * Radius*Radius;
}

int main()
{
	double Radius;
	cin >> Radius;
	Cirle cirle;
	cirle.Func1(Radius);
	cirle.Func2(Radius);
	system("pause");
}