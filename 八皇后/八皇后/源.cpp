#include <iostream>

using namespace std;

const int StackSize = 8;   //���ûʺ�����

template <class T>
class SeqStack
{
public:
	SeqStack() { top = -1; }                 //���캯��                             
	void Push(T x);                    //��ջ����                                  
	void Pop();                        //��ջ����                                
	void SetQueen(int row);            //���ûʺ�λ��                                
	bool Feasible();                   //�жϻʺ������                                      
	void Print();                     //��ӡ                                     
	bool Empty() { if (top == -1) return true; else return false; };    //�ж�ջ�Ƿ�Ϊ��     
private:
	T queen[StackSize];
	int top;
};

template <class T>
void SeqStack<T>::Push(T x)                                          //��ջ����
{
	if (top >= StackSize - 1) throw "ջ��";
	top++;
	queen[top] = x;
}

template <class T>
void SeqStack<T>::Pop()
{
	if (Empty()) throw "ջ����";
	top--;
}

int Count = 0;

template <class T>
void SeqStack<T>::SetQueen(int r)                   //���ûʺ�                   
{
	for (int i = 1; i <= StackSize; i++)
	{
		Push(i);
		if (Feasible())                        //�ж��Ƿ���԰ڷŻʺ�                       
		{
			if (r < StackSize - 1)
				SetQueen(r + 1);
			else
			{
				Count++;
				Print();
			}
		}
		Pop();
	}

}

template <class T>
bool SeqStack<T>::Feasible()               //�������ж�
{
	for (int i = 0; i < top; i++)
		if (queen[top] == queen[i] || (abs(queen[top] - queen[i])) == (top - i))   //�жϻʺ���ͬһ�л�Խ�����
			return false;
	return true;
}

template <class T>
void SeqStack<T>::Print()
{
	cout << Count << ":" << endl;
	for (int i = 0; i < StackSize; i++)
	{
		cout << "��" << i + 1 << "�У�";
		cout << queen[i] << " ";
	}
	cout << endl;
}

void main()   //������
{
	SeqStack<int> Queen;
	Queen.SetQueen(0);
	system("pause");
}
