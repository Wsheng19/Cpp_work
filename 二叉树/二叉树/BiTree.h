#pragma once
using namespace std;

template<class T>
struct BiNode
{
	T data;
	BiNode<T> * lch;
	BiNode<T> * rch;
};

template<class T>
class BiTree
{
private:
	void Create(BiNode<T> * &R, T data[], int i);
	void Create(BiNode<T> * &R, BiNode<T> * r);
	void Release(BiNode<T> * R);
public:
	BiNode<T> * root;										//根节点
	BiTree(T data[]);										//构造函数
	BiTree(BiTree<T> &B);									//复制构造函数
	~BiTree();												//析构函数
	void PreOrder(BiNode<T> * R);							//前序遍历
	void InOrder(BiNode<T> * R);							//中序遍历
	void PostOrder(BiNode<T> * R);							//后序遍历
	void LevelOrder(BiNode<T> * R);							//层序遍历
	int NodeNum(BiNode<T> * R);								//求结点数
};

template<class T>
void BiTree<T>::Create(BiNode<T> * &R, T data[], int i)
{
	if (data[i - 1] != 0)
	{
		R = new BiNode<T>;
		R->data = data[i - 1];
		R->lch = NULL;
		R->rch = NULL;
		Create(R->lch, data, 2 * i);
		Create(R->rch, data, 2 * i + 1);
	}
}

template<class T>
void BiTree<T>::Create(BiNode<T> * &R, BiNode<T> * r)
{
	if (r != NULL)
	{
		R = new BiNode<T>;
		R->data = r->data;
		R->lch = NULL;
		R->rch = NULL;
		Create(R->lch, r->lch);
		Create(R->rch, r->rch);
	}
}

template<class T>
BiTree<T>::BiTree(T data[])
{
	Create(root, data, 1);
}

template<class T>
BiTree<T>::BiTree(BiTree<T> &B)
{
	Create(root, B.root);
}

template<class T>
void BiTree<T>::Release(BiNode<T> * R)
{
	if (R != NULL)
	{
		Release(R->lch);
		Release(R->rch);
		delete R;
	}
}

template<class T>
BiTree<T>::~BiTree()
{
	Release(root);
}

template<class T>
void BiTree<T>::PreOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		cout << R->data << ' ';
		PreOrder(R->lch);
		PreOrder(R->rch);
	}
}

template<class T>
void BiTree<T>::InOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		InOrder(R->lch);
		cout << R->data << ' ';
		InOrder(R->rch);
	}
}

template<class T>
void BiTree<T>::PostOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		PostOrder(R->lch);
		PostOrder(R->rch);
		cout << R->data << ' ';
	}
}

template<class T>
void BiTree<T>::LevelOrder(BiNode<T> * R)
{
	BiNode<T> * queue[10000];
	int f = 0, r = 0;
	if (R != NULL) queue[++r] = R;
	while (f != r)
	{
		BiNode<T> * p = queue[++f];
		cout << p->data << ' ';
		if (p->lch != NULL)
			queue[++r] = p->lch;
		if (p->rch != NULL)
			queue[++r] = p->rch;
	}
}

template<class T>
int BiTree<T>::NodeNum(BiNode<T> * R)
{
	BiNode<T> * queue[10000];
	int f = 0, r = 0;
	if (R != NULL) queue[++r] = R;
	while (f != r)
	{
		BiNode<T> * p = queue[++f];
		if (p->lch != NULL)
			queue[++r] = p->lch;
		if (p->rch != NULL)
			queue[++r] = p->rch;
	}
	return r;
}