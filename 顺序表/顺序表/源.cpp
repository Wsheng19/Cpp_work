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
	cout << "ͨѶ¼�����б�\n";
	list.PrintList();
	list.Insert(1, record);
	cout << "ͨѶ¼�����б�\n";
	list.PrintList();
	PHONEBOOK x = list.Delete(1);
	cout << "ɾ��Ԫ��Ϊ��\n";
	x.print();
	cout << "ͨѶ¼�����б�\n";
	list.PrintList();
	int p = list.Locate(pbook[0]);
	cout << "Phoenix��λ���ǣ�" << p << endl;
	system("pause");
}