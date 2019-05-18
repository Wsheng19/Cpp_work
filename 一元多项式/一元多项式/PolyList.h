#pragma once
#include<iostream>
#include<cmath>
#include"LinkList.h"

struct element
{
	double coef;                       //ϵ��
	int exp;                           //ָ��
	element(double c = 0, int e = 0) :coef(c), exp(e) {}
};

class PolyList :public LinkList<element>
{
public:
	PolyList() :LinkList() {};                                       //�޳�ʼֵ���캯��
	PolyList(element data[], int n) :LinkList(data, n) {}            //���캯��
	void Input();                                                    //һԪ����ʽ������
	void Insert(element data);                                       //����
	void Add(PolyList & B);                                          //���
	void Opposite();                                                 //���෴��
	void Minus(PolyList & B);                                        //����
	void Derivation();                                               //��
	void Multiply(PolyList & B);                                     //���
	double Eval(double x);                                           //��ֵ����
	void PrintList()                                                 //һԪ����ʽ�����
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
	cout << "���������ʽ�ж�����";
	cin >> n;
	element * In = new element[n];
	cout << "������Ա�����ָ����С�������������ϵ����ָ��\n";
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
	cout << "�������\n";
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