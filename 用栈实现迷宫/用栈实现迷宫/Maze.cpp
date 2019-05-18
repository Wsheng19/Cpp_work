#include<iostream>
#include"Maze.h"

using namespace std;

int main()
{
	Point cur, End;
	cout << "请输入迷宫大小(行 列)：";
	int X, Y;
	cin >> X >> Y;
	int ** arr = Maze_design(X, Y, cur, End);
	Maze_run(X, Y, arr, cur, End);
	delete arr;
	system("pause");
}