/*
����һϵ������������������������������ǰ�����򣬺��������
����������
�����һ�а���һ������n(1<=n<=100)��
��������һ�а���n��������
���������
�����ж���������ݣ�����ÿ�����ݣ�����Ŀ�������ݽ���һ�����������������Զ�������������ǰ������ͺ��������
ÿ�ֱ���������һ�С�ÿ�����һ������֮����һ���ո�

�����п������ظ�Ԫ�أ���������Ķ����������������ظ�Ԫ�ز��������
*/
//�������������������ڵ�ֵ�ض�С�ڵ�������ڵ㣬�������ڵ�ֵ�ض����ڵ�������ڵ�
//��ȵ�����£��Ӿ������������ߺ���
/*
    4
   / \
  2   6
 / \
1  3
*/
#include <iostream>
using namespace std;
class Node
{
public:
	int val;
	Node *lchild, *rchild;
	Node(int val)
	{
		this->val = val;
		lchild = rchild = NULL;
	}
};
void PreOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->val << " ";
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void InOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->lchild);
	cout << root->val << " ";
	InOrder(root->rchild);
}
void PostOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->val << " ";
	delete root;
}

Node* Insert(Node *root, int val)
{
	if (root == NULL)
	{
		root = new Node(val);
		return root;
	}
	if (val < root->val) //�ȸ��ڵ�С������������
	{
		root->lchild = Insert(root->lchild, val);
	}
	else if (val > root->val) //�ȸ��ڵ�󣬲���������
	{
		root->rchild = Insert(root->rchild, val);
	}
	/*else if (val == root->val)  //���ֱ�Ӻ���
	{
		return NULL;
	}*/
	return root;
}
void Test(Node *root)
{
	root->lchild = new Node(2);
	root->rchild = new Node(3);
}
int main()
{
	int n;
	while (cin >> n)
	{
		int t;
		Node *root = NULL;
		for (int i = 0; i < n; i++)
		{
			cin >> t;
			root = Insert(root, t);
		}
		PreOrder(root);
		cout << endl;
		InOrder(root);
		cout << endl;
	    PostOrder(root);
		cout << endl;
	}
	return 0;
}