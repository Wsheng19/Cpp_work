#pragma once
#include<iostream>
#include<cmath>
#include"LinkList.h"

struct element
{
	double coef;                       //系数
	int exp;                           //指数
	element(double c = 0, int e = 0) :coef(c), exp(e) {}
};

class PolyList :public LinkList<element>
{
public:
	PolyList() :LinkList() {};                                       //无初始值构造函数
	PolyList(element data[], int n) :LinkList(data, n) {}            //构造函数
	void Input();                                                    //一元多项式的输入
	void Insert(element data);                                       //插入
	void Add(PolyList & B);                                          //求和
	void Opposite();                                                 //求相反数
	void Minus(PolyList & B);                                        //做差
	void Derivation();                                               //求导
	void Multiply(PolyList & B);                                     //相乘
	double Eval(double x);                                           //赋值运算
	void PrintList()                                                 //一元多项式的输出
	{
		Node<element> * p = GetFirst()->next;
		while (p) {
			cout << "(" << p->data.coef << "," << p->data.exp << ")";
			p = p->next;
		}
		cout << endl;
	}
};

void PolyList::Input()
{
	int n;
	cout << "请输入多项式有多少项";
	cin >> n;
	element * In = new element[n];
	cout << "请根据自变量的指数从小变大依次输入其系数和指数\n";
	for (int i = 0; i < n; i++)
	{
		double coef;
		int exp;
		cin >> coef >> exp;
		In[i].coef = coef;
		In[i].exp = exp;
	}
	PolyList x(In, n);
	Add(x);
	cout << "输入完成\n";
	delete In;
}

void PolyList::Insert(element data)
{
	Node<element> * p_prior = GetFirst()->next;
	if (p_prior == NULL)
	{
		Node<element> * p = new Node<element>;
		p->data = data;
		p->next = NULL;
		p_prior = p;
	}
	else
	{
		while (p_prior->data.exp < data.exp)
			p_prior = p_prior->next;
		if (p_prior == NULL)
		{
			Node<element> * p = new Node<element>;
			p->data = data;
			p->next = NULL;
			p_prior = p;
		}
		else if (p_prior->data.exp == data.exp)
			p_prior->data.coef = p_prior->data.coef + data.coef;
		else if (p_prior->data.exp > data.exp)
		{
			Node<element> * s = new Node<element>;
			s->data = p_prior->data;
			s->next = p_prior->next;
			p_prior->next = s;
			p_prior->data = data;
		}
	}
}

void PolyList::Add(PolyList & B)
{
	Node<element> * p_prior = GetFirst();
	Node<element> * p = p_prior->next;
	Node<element> * q = B.GetFirst()->next;
	while (p && q)
	{
		if (p->data.exp < q->data.exp) {
			p_prior = p;
			p = p->next;
		}
		else if (p->data.exp > q->data.exp) {
			p_prior->next = q;
			p_prior = q;
			q = q->next;
			p_prior->next = p;
		}
		else {
			p->data.coef += q->data.coef;
			if (fabs(p->data.coef) < 1e-7) {
				p_prior->next = p->next;
				delete p;
				p = p_prior->next;
			}
			else {
				p_prior = p;
				p = p_prior->next;
			}
			Node<element> * temp = q;
			q = q->next;
			delete temp;
		}
	}
	if (q) p_prior->next = q;
	B.GetFirst()->next = NULL;
}

void PolyList::Opposite()
{
	Node<element> * p = GetFirst()->next;
	while (p) {
		p->data.coef *= -1;
		p = p->next;
	}
}

void PolyList::Minus(PolyList & B)
{
	B.Opposite();
	Add(B);
}

void PolyList::Derivation()
{
	Node<element> * p = GetFirst()->next;
	while (p) {
		if (p->data.exp == 0)
		{
			p = p->next;
			element m = Delete(1);
		}
		else
		{
			p->data.coef = p->data.coef * p->data.exp;
			p->data.exp -= 1;
			p = p->next;
		}
	}
}

double PolyList::Eval(double x)
{
	Node<element> * p = GetFirst()->next;
	double total = 0;
	while (p) {
		total += p->data.coef * powf(x, p->data.exp);
		p = p->next;
	}
	return total;
}

void PolyList::Multiply(PolyList & B)
{
	Node<element> * p = GetFirst()->next;
	Node<element> * q = B.GetFirst()->next;
	int len = GetLength() - 1;
	PolyList t;
	while (q)
	{
		element * a = new element[len];
		for (int i = 0; i < len; i++)
		{
			a[i].coef = q->data.coef * p->data.coef;
			a[i].exp = q->data.exp + p->data.exp;
			p = p->next;
		}
		PolyList b(a, len);
		t.Add(b);
		delete a;
		q = q->next;
		p = GetFirst()->next;
	}
	t.PrintList();
}