#include <iostream>

using namespace std;

const int StackSize = 8;   //设置皇后数组

template <class T>
class SeqStack
{
public:
	SeqStack() { top = -1; }                 //构造函数                             
	void Push(T x);                    //入栈操作                                  
	void Pop();                        //出栈操作                                
	void SetQueen(int row);            //设置皇后位置                                
	bool Feasible();                   //判断皇后可行性                                      
	void Print();                     //打印                                     
	bool Empty() { if (top == -1) return true; else return false; };    //判断栈是否为空     
private:
	T queen[StackSize];
	int top;
};

template <class T>
void SeqStack<T>::Push(T x)                                          //入栈操作
{
	if (top >= StackSize - 1) throw "栈满";
	top++;
	queen[top] = x;
}

template <class T>
void SeqStack<T>::Pop()
{
	if (Empty()) throw "栈下溢";
	top--;
}

int Count = 0;

template <class T>
void SeqStack<T>::SetQueen(int r)                   //设置皇后                   
{
	for (int i = 1; i <= StackSize; i++)
	{
		Push(i);
		if (Feasible())                        //判断是否可以摆放皇后                       
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
bool SeqStack<T>::Feasible()               //可行性判断
{
	for (int i = 0; i < top; i++)
		if (queen[top] == queen[i] || (abs(queen[top] - queen[i])) == (top - i))   //判断皇后不在同一列或对角线上
			return false;
	return true;
}

template <class T>
void SeqStack<T>::Print()
{
	cout << Count << ":" << endl;
	for (int i = 0; i < StackSize; i++)
	{
		cout << "第" << i + 1 << "行：";
		cout << queen[i] << " ";
	}
	cout << endl;
}

void main()   //主函数
{
	SeqStack<int> Queen;
	Queen.SetQueen(0);
	system("pause");
}
