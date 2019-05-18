#include<iostream>
#include<string>
#include"LinkList.h"
using namespace std;

int main()
{
	PHONEBOOK pbook[4] = 
	{{20181209,"Mary","13011221827","classmates"},
	{20181127,"Tom","13934621123","familly"},
	{20181156,"John","13245798802","classmates"},
	{20181133,"Lisa","13780018220","classmates"}
	};
	PHONEBOOK record(20181209, "Phoenix", "15930209020","teacher");
	LinkList<PHONEBOOK>list(4,pbook);
	cout << "通讯录内容列表：\n";
	list.PrintList();
	list.Insert(record, 1);
	cout << "通讯录内容列表：\n";
	list.PrintList();
	PHONEBOOK x = list.Delete(2);
	cout << "删除元素是：" << endl;
	x.print();
	cout << "通讯内容列表：\n";
	list.PrintList();
	int p = list.Locate(record);
	cout << "Phoenix的位置是：" << p << endl;
	system("pause");
}