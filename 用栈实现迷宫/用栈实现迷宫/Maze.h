#pragma once
#include<iostream>

using namespace std;

struct Point
{
	int X, Y;
};

//�Թ���ƺ���
int** Maze_design(int X, int Y, Point &cur, Point &End)
{
	int ** arr;
	arr = new int *[X + 1];
	for (int i = 0; i <= X; i++)
		arr[i] = new int[Y + 1];
	cout << "��һ��һ��������������Թ�(-1�����ϰ���0����ͨ·)\n";
	for (int i = 1; i <= X; i++)
		for (int j = 1; j <= Y; j++)
			cin >> arr[i][j];
	cout << "���������λ�ã�";
	//cin >> cur.X >> cur.Y;
	int cur_X, cur_Y;
	cin >> cur_X >> cur_Y;
	if (cur_X > X || cur_Y > Y)
	{
		cout << "������������������������λ�ã�";
		cin >> cur_X >> cur_Y;
	}
	cur.X = cur_X;
	cur.Y = cur_Y;
	cout << "�������յ�λ�ã�";
	//cin >> End.X >> End.Y;
	int End_X, End_Y;
	cin >> End_X >> End_Y;
	if (End_X > X || End_Y > Y)
	{
		cout << "�յ��������������������յ㣺";
		cin >> End_X >> End_Y;
	}
	End.X = End_X;
	End.Y = End_Y;
	return arr;
}

//����ջ����Թ�����
void Maze_run(int X, int Y, int ** arr, Point cur, Point End)
{
	Point Stack[1024];
	int top = -1;
	do
	{
		arr[cur.X][cur.Y] = 2;
		top++;
		Stack[top].X = cur.X;
		Stack[top].Y = cur.Y;
		if (arr[cur.X][cur.Y + 1] == 0)                                     //������
			cur.Y++;
		else if (arr[cur.X + 1][cur.Y] == 0)                                //��������
			cur.X++;
		else if (arr[cur.X][cur.Y - 1] == 0)                                //��������
			cur.Y--;
		else if (arr[cur.X - 1][cur.Y] == 0)                                //������
			cur.X--;
		else
		{
			arr[Stack[top].X][Stack[top].Y] = 1;
			top--;
			cur.X = Stack[top].X;
			cur.Y = Stack[top].Y;
			top--;
		}
	} while ((top != -1) && ((cur.X != End.X) || (cur.Y != End.Y)));
	
	//��ӡ�Թ�ͨ··��
	/*int i = 0;
	while (i <= top)
	{
		cout << "(" << Stack[i].X << "," << Stack[i].Y << ") -> ";
		i++;
	}
	cout << "(" << End.X << "," << End.Y << ")\n";*/

	//��ӡ�Թ�ͨ·ͼ��
	arr[End.X][End.Y] = 2;
	for (int i = 1; i <= X; i++)
	{
		for (int j = 1; j <= Y; j++)
		{
			
			if (arr[i][j] == 2)
				cout << " *";
			else if (arr[i][j] == 0)
				cout << "  ";
			else
				cout << "��";
		}
		cout << endl;
	}
}
