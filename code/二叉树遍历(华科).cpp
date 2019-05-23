/*
����ǰ���������������ؽ���������
���磺ǰ��XDAGFE������ADGXFE
ǰ������׸��ڵ�XΪ���ڵ㣬��������У����ڵ㽫�����Ϊ������ADG X FE�ֱ�Ϊ�ýڵ�������������������ɵ�֪�ýڵ�
���������ڵ������ǰ������ýڵ�֮��Ľ��������������Ȼ������������������Եõ���������ǰ�����DAG���������ADG��
������ǰ�����FE���������FE��������������ͬ����������
�ݹ����
*/
#include <iostream>
#include <string>
using namespace std;
string preorder, minorder;    //ǰ�����������������
int prelen, midlen;
class Node
{
public :
	char val;
	Node *lchild, *rchild;
	Node(char ini)
	{
		val = ini;
		lchild = NULL;
		rchild = NULL;
	}
	Node()
	{
		val = ' ';
		lchild = NULL;
		rchild = NULL;
	}
};
void PostOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->val;
	delete root;   //������ýڵ������ӽڵ��ɾ���ýڵ�
}
//�ݹ����
Node* Build(int pres, int pree, int mids, int mide)   //pres��pree���嵱ǰǰ������mids��mideΪ��ǰ������
{
	char val = preorder[pres];
	Node *root = new Node(val);
	int index = minorder.find(val);
	if (mids != index) //��������Ϊ��
	{
		int len = index - mids;  //������������
		root->lchild = Build(pres + 1, len + pres, mids, index - 1);
	}
	if (mide != index) //��������Ϊ��
	{
		int len = mide - index;
		root->rchild = Build(pree + 1 - len, pree, index + 1, mide);
	}

	return root;
}
int main()
{
	while (cin >> preorder >> minorder)
	{
		prelen = preorder.length();
		midlen = minorder.length();
		Node *root = Build(0, prelen - 1, 0, midlen - 1);
		PostOrder(root);
		cout << endl;
	}
}