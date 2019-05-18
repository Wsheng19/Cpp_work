#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T, int N>

class SeqList
{
public:
	SeqList() { length = 0; }
	SeqList(T a[], int n);
	int GetLength() { return length; }
	void PrintList();
	void Insert(int i, T x);
	T Delete(int i);
	T Get(int i);
	int Locate(T x);
private:
	T data[N];
	int length;
};

template<class T, int N>
SeqList<T, N>::SeqList(T a[], int n)
{
	if (n > N) throw"数组长度超过顺序表的最长长度";
	for (int i = 0; i < n; i++)
		data[i] = a[i];
	length = n;
}

template<class T, int N>
void SeqList<T, N>::PrintList()
{
	cout << "按序号依次遍历线性表中的各个数据元素:" << endl;
	for (int i = 0; i < length; i++)
		data[i].print();
	cout << endl;
}

template<class T, int N>
void SeqList<T, N>::Insert(int i, T x)
{
	if (i > N)throw"上溢异常";
	if (i<1 || i>length + 1)throw"位置异常";
	for (int j = length; j >= i; j--)
		data[j] = data[j - 1];
	data[i - 1] = x;
	length++;
}

template<class T, int N>
T SeqList<T, N>::Delete(int i)
{
	if (length == 0)throw"下溢异常";
	if (i<1 || i>length)throw"位置异常";
	T x = data[i - 1];
	for (int j = i; j < length; j++)
		data[j - 1] = data[j];
	length--;
	return x;
}

template<class T, int N>
T SeqList<T, N>::Get(int i)
{
	if (i<1 || i>length)throw"查找位置异常";
	return data[i - 1];
}

template<class T, int N>
int SeqList<T, N>::Locate(T x)
{
	for (int i = 0; i < length; i++)
		if (data[i] == x)
			return i + 1;
	return 0;
}

class PHONEBOOK
{
private:
	int m_ID;
	string m_name;
	string m_phone;
	string m_group;
public:
	PHONEBOOK() {}
	PHONEBOOK(int ID, string name, string phone, string group) {
		m_ID = ID;
		m_name = name;
		m_phone = phone;
		m_group = group;
	}
	void print() {
		cout << m_ID << '\t' << m_name << '\t' << m_phone << '\t' << m_group << endl;
	}
	bool operator==(PHONEBOOK&p) {
		if (p.m_ID == m_ID)
			return true;
		return false;
	}
};

