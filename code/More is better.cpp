#include <iostream>
#define SIZE 10000005
using namespace std;
int Tree[SIZE];
int sum[SIZE];
void Ini()
{
	for (int i = 0; i < SIZE; i++)
	{
		Tree[i] = -1;
		sum[i] = 1;
	}
}
int findRoot(int x)
{
	if (Tree[x] == -1)
	{
		return x;
	}
	int t = findRoot(Tree[x]);
	Tree[x] = t;
	return t;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int a, b;
		Ini();
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)   //�����ѵ������˲���ͬһ������
			{
				Tree[a] = b;  //��b��Ϊa�ĸ��ڵ�
				sum[b] += sum[a]; //ͳ������
			}
		}
		int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (Tree[i] == -1)
			{
				if (sum[i] > ans)
				{
					ans = sum[i];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}