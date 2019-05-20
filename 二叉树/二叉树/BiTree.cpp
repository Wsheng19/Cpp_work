#include<iostream>
#include"BiTree.h"
using namespace std;

int main()
{
	char data[10000] = {0};
	data[0] = 'A';
	data[1] = 'B';
	data[2] = 'C';
	data[3] = 'D';
	data[4] = 'E';
	data[5] = 'G';
	data[9] = 'F';
	//����������tree
	BiTree<char> tree(data);
	cout << "ǰ�����Ϊ��";
	tree.PreOrder(tree.root);
	cout << "\n�������Ϊ��";
	tree.InOrder(tree.root);
	cout << "\n�������Ϊ��";
	tree.PostOrder(tree.root);
	cout << "\n��α���Ϊ��";
	tree.LevelOrder(tree.root);
	//��tree���Ƹ�tree_1
	BiTree<char> tree_1 = tree;
	//����tree_1�����tree_1��ǰ��������
	cout << "\nǰ�����Ϊ��";
	tree_1.PreOrder(tree_1.root);
	cout << "\ntree_1�Ľ��һ���У�" << tree_1.NodeNum(tree_1.root) << endl;
	cout << "��Ҷ�ӽ�㵽����·��Ϊ��";
	tree_1.printPath(tree_1.root, tree_1.root->lch->rch->lch);
	cout << endl;
	system("pause");
}