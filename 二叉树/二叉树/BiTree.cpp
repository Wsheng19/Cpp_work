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
	//创建二叉树tree
	BiTree<char> tree(data);
	cout << "前序遍历为：";
	tree.PreOrder(tree.root);
	cout << "\n中序遍历为：";
	tree.InOrder(tree.root);
	cout << "\n后序遍历为：";
	tree.PostOrder(tree.root);
	cout << "\n层次遍历为：";
	tree.LevelOrder(tree.root);
	//将tree复制给tree_1
	BiTree<char> tree_1 = tree;
	//测试tree_1，输出tree_1的前序遍历结果
	cout << "\n前序遍历为：";
	tree_1.PreOrder(tree_1.root);
	cout << "\ntree_1的结点一共有：" << tree_1.NodeNum(tree_1.root) << endl;
	cout << "从叶子结点到根的路径为：";
	tree_1.printPath(tree_1.root, tree_1.root->lch->rch->lch);
	cout << endl;
	system("pause");
}