#include<iostream>
#include"Maze.h"

using namespace std;

int main()
{
	Point cur, End;
	cout << "�������Թ���С(�� ��)��";
	int X, Y;
	cin >> X >> Y;
	int ** arr = Maze_design(X, Y, cur, End);
	Maze_run(X, Y, arr, cur, End);
	delete arr;
	system("pause");
}