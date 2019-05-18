#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:
	int number;
	string name;
	int salary;
	int year;
	int month;
	int day;
public:
	Employee(int, string, int, int, int, int);
	//void employee(int, string, int, int, int, int);
	void totalsalary(int, int);
};

Employee::Employee(int num, string n, int s, int y, int m, int d)
{
	number = num;
	name = n;
	salary = s;
	year = y;
	month = m;
	day = d;
}

/*void Employee::employee(int num, string n, int s, int y, int m, int d)
{
	number = num;
	name = n;
	salary = s;
	year = y;
	month = m;
	day = d;
}和后面的一起*/

void Employee::totalsalary(int y, int m)
{
	int sum = 0;
	sum += (y - year) * 12;
	sum += m - month;
	sum *= salary;
	cout << name << ' ' << sum;
}

int main()
{
	Employee emp[5] = {
		Employee(1,"wang",5000,2000,10,23),
		Employee(2,"liu",4500,2008,1,20),
		Employee(3,"huo",3800,2003,7,3),
		Employee(4,"ma",5300,2015,4,10),
		Employee(5,"meng",6000,2016,3,16)
	};
	/*Employee emp[5];
	emp[1].employee(1, "wang", 5000, 2000, 10, 23);
	emp[2].employee(2, "liu", 4500, 2008, 1, 20);
	emp[3].employee(3, "huo", 3800, 2003, 7, 3);
	emp[4].employee(4, "ma", 5300, 2015, 4, 10);
	emp[5].employee(5, "meng", 6000, 2016, 3, 16);//效果等价，你比较一下，这就是构造函数的方便之处*/
	int n, y, m;
	cin >> n >> y >> m;
	emp[n-1].totalsalary(y, m);
	system("pause");
}