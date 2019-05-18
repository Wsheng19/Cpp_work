#include<iostream>
using namespace std;

void Func(int *A, int nSize)
{
	for (int i = 0; i < nSize;i++)//冒泡排序，第一次排序（降序）
	{
		for (int j = 0; j < nSize - 1; j++)
		{
			if (A[j] < A[j + 1])
			{
				int flag = A[j];
				A[j] = A[j + 1];
				A[j + 1] = flag;
			}
		}
	}
	for (int i = 0; i < nSize; i++)//第二次排序，升序，并且将0保留在最后
	{
		for (int j = 0; j < nSize - 1; j++)
		{
			if (A[j + 1] && (A[j] > A[j + 1]))
			{
				int flag = A[j];
				A[j] = A[j + 1];
				A[j + 1] = flag;
			}
		}
	}
	for (int i = 0; i < nSize - 1; i++) cout << A[i] << ' ';
	cout << A[nSize-1];
}

int main()
{
	int nSize, *A;
	cin >> nSize;
	A = new int[nSize];//用new申请动态数组
	for (int i = 0; i < nSize; i++) cin >> A[i];
	Func(A, nSize);
	delete[]A;//释放堆空间
	system("pause");
}