#include<iostream>
#include"SeqList.h"
#include<string>
using namespace std;

int main()
{
	PHONEBOOK pbook[4] = { {20181208,"Marry","13011221827","classmates"},
	{20181127,"Tom","13934621123","family"},
	{20181156,"John","13245798802","classmates"},
	{20181133,"Lisa","13780018223","classmates"} };
	PHONEBOOK record(20181209, "Phoenix", "15930209020", "teacher");
	SeqList<PHONEBOOK, 100>list(pbook, 4);
	cout << "通讯录内容列表：\n";
	list.PrintList();
	list.Insert(1, record);
	cout << "通讯录内容列表：\n";
	list.PrintList();
	PHONEBOOK x = list.Delete(1);
	cout << "删除元素为：\n";
	x.print();
	cout << "通讯录内容列表：\n";
	list.PrintList();
	int p = list.Locate(pbook[0]);
	cout << "Phoenix的位置是：" << p << endl;
	system("pause");
}