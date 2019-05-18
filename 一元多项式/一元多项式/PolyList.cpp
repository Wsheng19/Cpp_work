#include<iostream>
#include"LinkList.h"
#include"PolyList.h"

using namespace std;

int main()
{
	element ea[] = { element(1,0),element(2.3,2),element(3,4) };
	PolyList a(ea, 3);
	PolyList b;
	b.Input();
	a.PrintList();
	a.Minus(b);
	a.PrintList();
	a.Derivation();
	a.PrintList();
	a.Multiply(b);
	double c = a.Eval(2);
	cout << c;
	system("pause");
}