#include<iostream>
using namespace std;

void Func(int *A, int nSize)
{
	for (int i = 0; i < nSize;i++)//ð�����򣬵�һ�����򣨽���
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
	for (int i = 0; i < nSize; i++)//�ڶ����������򣬲��ҽ�0���������
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
	A = new int[nSize];//��new���붯̬����
	for (int i = 0; i < nSize; i++) cin >> A[i];
	Func(A, nSize);
	delete[]A;//�ͷŶѿռ�
	system("pause");
}