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
	cout << "ͨѶ¼�����б�\n";
	list.PrintList();
	list.Insert(record, 1);
	cout << "ͨѶ¼�����б�\n";
	list.PrintList();
	PHONEBOOK x = list.Delete(2);
	cout << "ɾ��Ԫ���ǣ�" << endl;
	x.print();
	cout << "ͨѶ�����б�\n";
	list.PrintList();
	int p = list.Locate(record);
	cout << "Phoenix��λ���ǣ�" << p << endl;
	system("pause");
}