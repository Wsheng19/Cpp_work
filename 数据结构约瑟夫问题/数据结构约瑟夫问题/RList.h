#pragma once
#include<iostream>
using namespace std;

struct Node
{
	int number;
	Node * next;
};


class RList
{
private:
	Node * front;
public:
	RList() { front = new Node; front->next = NULL; }
	RList(int a[], int per_n);
	~RList();
	void PrintList();
	int GetLength();
	Node * loc(int i);
	void Delete(int i);
	int Josephus(int m);
};

RList::RList(int a[], int per_n)
{
	front = new Node;
	Node * p = front;
	for (int i = 0; i < per_n; i++)
	{
		Node * s = new Node;
		s->number = a[i];
		p->next = s;
		p = s;
	}
	p->next = front->next;
}

RList::~RList()
{
	Node * p = front->next;
	while (p->next != p)
	{
		Node * q = p->next;
		p->next = q->next;
		delete q;
	}
	delete p;
	delete front;
}

void RList::PrintList()
{
	Node * p = front->next;
	int i = 1;
	while (p->next != front->next)
	{
		cout << i++ << ':' << p->number << ' ';
		p = p->next;
	}
	cout << i << ':' << p->number << endl;
}

int RList::GetLength()
{
	if (front->next == NULL) return 0;
	Node * p = front->next;
	int i = 1;
	while (p->next != front->next)
	{
		p = p->next;
		i++;
	}
	return i;
}

Node * RList::loc(int i)
{
	Node * p = front->next;
	int n = 1;
	if (i > GetLength() || i < 0) throw"位置错误";
	else if (i == 0) return front;
	while (n < i)
	{
		p = p->next;
		n++;
	}
	return p;
}

void RList::Delete(int i)
{
	if (i<0 || i>GetLength())throw"删除位置错误";
	Node * p = loc(i - 1);
	Node * q = p->next;
	p->next = q->next;
	delete q;
}

//约瑟夫问题的实现
int RList::Josephus(int m)
{
	Node * p = front->next;
	int count = 1;
	while (p->next != p)
	{
		if (count == m - 1)
		{
			Node * q = p->next;
			p->next = q->next;
			p = q->next;
			delete q;
			count = 1;
		}
		else
		{
			p = p->next;
			count++;
		}
	}
	front->next = p;
	return p->number;
}