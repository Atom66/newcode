#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define SIZE 2005
int Tree[SIZE];
int head[SIZE];			//���ܰ��ɵĸ��ڵ�
int sum[SIZE];			//�����˵���ʱ��
int cnt[SIZE];     //�����ܼ�
int findRoot(int x)
{
	if (Tree[x] == x)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
};
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		Tree[i] = i;
		sum[i] = 0;
		cnt[i] = 1;
		head[i] = i;
	}
}
string getName(map<string, int> name2id, int value)
{
	map<string, int>::iterator it;
	for (it = name2id.begin(); it != name2id.end(); it++)
	{
		if (it->second == value)
		{
			return it->first;
		}
	}
	return "NO";
}
class Node
{
public:
	string name;
	int weight;
	Node(string name, int w)
	{
		this->name = name;
		weight = w;
	}
	Node()
	{
		name = "";
		weight = 0;
	}
	bool operator < (const Node &A) const
	{
		return name < A.name;
	}
};
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		map<string, int> name2id;
		Ini();
		string a, b;
		int time;
		int headCnt = 0;		//���ܰ�������
		int numCnt = 1;    //�ַ���ת����
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b >> time;
			//�ַ���ת���Ͳ���¼
			if (name2id[a] == 0)
			{
				name2id[a] = numCnt++;
			}
			if (name2id[b] == 0)
			{
				name2id[b] = numCnt++;
			}
			//��ȡ��ǰ��������1������
			int n1 = name2id[a];
			int n2 = name2id[b];
			//��¼ÿ���ڵ����ʱ��
			sum[n1] += time;
			sum[n2] += time;
			n1 = findRoot(n1);
			n2 = findRoot(n2);
			if (n1 != n2)
			{
				Tree[n1] = n2;
				cnt[n2] += cnt[n1];
			}
		}
		//Check(name2id);
		int ans = 0;
		for (int i = 1; i <= numCnt; i++)
		{
			if (cnt[i] > 2 && Tree[i] == i) //����������������2�Ҹýڵ��Ǹ��ڵ�
			{
				head[headCnt++] = i;    //��¼�¿��ܰ��ɵĸ��ڵ�
			}
		}
		Node node[SIZE];
		//�������м���Ԫ����������2�ļ���
		for (int i = 0; i < headCnt; i++)
		{
			int root = head[i];   //ĳ���ϵĸ��ڵ�
			int t = 0; //total weight
			int larw = 0;  //�������
			int head = 0;  //head
			for (int j = 1; j <= numCnt; j++)
			{
				if (findRoot(j) == root)
				{
					t += sum[j];
					if (sum[j] > larw)
					{
						larw = sum[j];
						head = j;
					}
				}
			}
			//����ÿ����ϵ�У�˫����sumֵ�������weight�����ȫ��Ԫ��sum���Ϊ������Ȩ�ص�����
			if (t / 2 > k)   //�ܹ�ϵ����k����һ������
			{
				string name = getName(name2id, head);
				node[ans++] = Node(name, cnt[root]);  //��¼��ͷ
			}
		}
		sort(node, node + ans);
		cout << ans << endl;
		for (int i = 0; i < ans; i++)
		{
			cout << node[i].name << " " << node[i].weight << endl;
		}
	}
	return 0;
}