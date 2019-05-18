#include<iostream>
#include<string>
using namespace std;

class Staff
{
private:
	string level;
public:
	Staff(string level) { this->level = level; }
	void Print() { cout << level << endl; }
	string getlevel() { return level; }
};

class Teacher
{
private:
	string title;
public:
	Teacher(string ti) { title = ti; }
	void Print() { cout << title << endl; }
	string gettitle() { return title; }
};

class Staffteacher :public Staff, public Teacher
{
private:
	string name;
public:
	Staffteacher(string, string, string);
	void Print() { cout << name << endl; }
	void Printall();
};

Staffteacher::Staffteacher(string level, string title, string n) :Staff(level), Teacher(title) { name = n; }

void Staffteacher::Printall()
{
	cout << name << endl << "级别是" << getlevel() << endl << "职称是" << gettitle();
}

int main()
{
	string level, title, name;
	cin >> level >> title >> name;
	Staffteacher st(level, title, name);
	st.Printall();
	system("pause");
}