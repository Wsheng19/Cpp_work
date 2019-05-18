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
	BiTree<char> tree(data);
	tree.LevelOrder(tree.root);
	BiTree<char> tree_1 = tree;
	tree_1.PreOrder(tree_1.root);
	cout << tree_1.NodeNum(tree_1.root);
	system("pause");
}