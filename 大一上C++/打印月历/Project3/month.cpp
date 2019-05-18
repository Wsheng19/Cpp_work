#include<iostream>
#include<iomanip>
#include"month.h"
using namespace std;

void printMonthTitle(int year, int month)
{
	char chMonth[12][7] = { "一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月" };
	cout << endl
		<< setw(12) << year << "年" << "  "
		<< chMonth[month - 1] << endl
		<< "_______________________" << endl
		<< "Sun Mon Tue Wed Thu Fri Sat" << endl;
}

void printMonthBody(int year, int month)
{
	int startDay = getStartDay(year, month);
	int numberOfDaysInMonth = getNumberOfDaysInMonth(year, month);
	int i = 0;
	for (i = 0; i < startDay; i++)
		cout << "  ";
	for (i = 1; i <= numberOfDaysInMonth; i++)
	{
		cout << setw(4) << i;
		if ((i + startDay) % 7 == 0)
			cout << endl;
	}
	cout << endl
		<< "______________________" << endl;
}

int getStartDay(int year, int month)
{
	int startDay1800 = 3;
	//1800年1月1日至当月的总天数
	int totalNumberOfDays = getTotalNumberOfDays(year, month);
	//Return the start day
	return(totalNumberOfDays + startDay1800) % 7;
}

int getTotalNumberOfDays(int year, int month)
{
	int total = 0;
	for (int i = 1800; i < year; i++)
	{
		if (isLeapYear(i)) total += 366;
		else total += 365;
	}
	for (int i = 1; i < month; i++)
		total += getNumberOfDaysInMonth(year, i);
	return total;
}

int getNumberOfDaysInMonth(int year, int month)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if (month == 2)
		return isLeapYear(year) ? 29 : 28;
	return 0;
}

bool isLeapYear(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year & 100 != 0);
}