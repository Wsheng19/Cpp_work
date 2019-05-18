#pragma once
using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T> * next;
};

template<class T>
class LinkList
{
private:
	Node<T> * front;
public:
	LinkList() { front = new Node<T>; front->next = NULL; }
	LinkList(T a[], int n);
	LinkList(int n, T a[]);
	~LinkList();
	Node<T> * GetFirst() { return front; }
	void PrintList();
	int GetLength();
	Node<T> * Get(int i);
	int Locate(T x);
	void Insert(T x, int i);
	T Delete(int i);
};

template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	front = new Node<T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T> * s = new Node<T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}
}

//书上代码
template<class T>
LinkList<T>::LinkList(int n, T a[])
{
	front = new Node<T>;
	Node<T> * r = front;
	for (int i = 0; i < n; i++)
	{
		Node<T> * s = new Node<T>;
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
	Node<T> * p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
}

template<class T>
void LinkList<T>::PrintList()
{
	Node<T> * p = front->next;
	while (p)
	{
		p->data.print();
		p = p->next;
	}
	cout << endl;
}

template<class T>
int LinkList<T>::GetLength()
{
	Node<T> * p = front;
	int i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}

template<class T>
Node<T> * LinkList<T>::Get(int i)
{
	if (i <= 0 || i > GetLength()) throw"位置异常";
	Node<T> * p = front->next;
	for (int j = 1; j < i && p != NULL; j++)
		p = p->next;
	return p;
}

template<class T>
int LinkList<T>::Locate(T x)
{
	Node<T> * p = front->next;
	int i = 1;
	while (p)
	{
		if (p->data == x) return i;
		p = p->next;
		i++;
	}
	return -1;
}

template<class T>
void LinkList<T>::Insert(T x, int i)
{
	if (i <= 0) throw"插入位置异常";
	Node<T> * p = front;
	int j = 0;
	while (p&&j++ != i - 1)
		p = p->next;
	if (p)
	{
		Node<T> * s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else throw"插入位置错误";
}

template<class T>
T LinkList<T>::Delete(int i)
{
	if (i <= 0 || i > GetLength())throw"删除位置异常";
	Node<T> * p = front;
	int j = 0;
	if (i != 1)
	{
		p = p->next;
		j++;
	}
	while (p&&j++ != i - 1)
		p = p->next;
	Node<T> * q = p->next;
	T x = q->data;
	p->next = q->next;
	delete q;
	return x;
}