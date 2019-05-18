#include<iostream>
#include<string>
using namespace std;
class  Student
{
public:
	Student(string, string,int);
	void Print();
	string getschuolName() { return schuolName; }
	string getstudentName() { return studentName; }
	int getAge() { return Age; }
private:
	string schuolName;
	string studentName;
	int Age;
};

Student::Student(string schuolname, string studentname,int age)
{
	schuolName = schuolname; studentName = studentname; Age = age;
}

void Student::Print()
{
	cout << schuolName << "大学的" << studentName << "年龄" << Age;
}

class G_Student :public Student
{
private:
	string teacherName;
public:
	G_Student(string, string, string, int);
	void Print();
};

G_Student::G_Student(string schuolname, string studentname, string teachername, int age):Student(schuolname,studentname,age)
{
	teacherName = teachername;
}

void G_Student::Print()
{
	cout << getschuolName() << "大学的" << getstudentName() << "年龄" << getAge() << "导师是" << teacherName;
}

int main()
{
	string schuolname, studentname, teachername; int age;
	cin >> schuolname >> studentname >> age >> teachername;
	G_Student stu(schuolname, studentname, teachername, age);
	stu.Print();
	system("pause");
}