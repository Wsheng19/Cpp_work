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
	BiNode<T> * root;										//���ڵ�
	BiTree(T data[]);										//���캯��
	BiTree(BiTree<T> &B);									//���ƹ��캯��
	~BiTree();												//��������
	void PreOrder(BiNode<T> * R);							//ǰ�����
	void InOrder(BiNode<T> * R);							//�������
	void PostOrder(BiNode<T> * R);							//�������
	void LevelOrder(BiNode<T> * R);							//�������
	int NodeNum(BiNode<T> * R);								//������
	bool printPath(BiNode<T> * R, BiNode<T> * r);			//�����Ҷ�ӽ�㵽����·��
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
}	//ʱ�临�Ӷȣ�O(n);

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
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
BiTree<T>::BiTree(T data[])
{
	Create(root, data, 1);
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
BiTree<T>::BiTree(BiTree<T> &B)
{
	Create(root, B.root);
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
void BiTree<T>::Release(BiNode<T> * R)
{
	if (R != NULL)
	{
		Release(R->lch);
		Release(R->rch);
		delete R;
	}
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
BiTree<T>::~BiTree()
{
	Release(root);
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
void BiTree<T>::PreOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		cout << R->data << ' ';
		PreOrder(R->lch);
		PreOrder(R->rch);
	}
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
void BiTree<T>::InOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		InOrder(R->lch);
		cout << R->data << ' ';
		InOrder(R->rch);
	}
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
void BiTree<T>::PostOrder(BiNode<T> * R)
{
	if (R != NULL)
	{
		PostOrder(R->lch);
		PostOrder(R->rch);
		cout << R->data << ' ';
	}
}	//ʱ�临�Ӷȣ�O(n);

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
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
int BiTree<T>::NodeNum(BiNode<T> * R)
{
	if (R == NULL) return 0;
	int m = NodeNum(R->lch);
	int n = NodeNum(R->rch);
	return m + n + 1;
}	//ʱ�临�Ӷȣ�O(n);

template<class T>
bool BiTree<T>::printPath(BiNode<T> * Root, BiNode<T> * r)
{
	if (Root == NULL)
		return false;
	if (Root == r || printPath(Root->lch, r) || printPath(Root->rch, r))
	{
		cout << Root->data << " ";
		return true;
	}
	return false;
}	//ʱ�临�Ӷȣ�O(n);