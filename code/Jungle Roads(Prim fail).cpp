#include<iostream>  //
#include <string.h>
using namespace std;
#define SIZE 28
bool visit[SIZE];
int map[SIZE][SIZE];
void Prim(int n)
{
	int cnt = 1; //�����нڵ���
	int ans = 0;
	int u;
	int len;
	visit[0] = true;
	while (cnt < n)
	{	
		len = -1;
		for (int i = 0; i < n; i++)
		{	
			if (!visit[i])
			{
				continue;
			}
			//�����ڼ����еĽڵ㣬������̵�·��
			for (int j = 0; j < n; j++)
			{
				//j��i֮����ͨ·�Ҿ�����С��j�Ǽ������
				if (map[i][j] != -1 && !visit[j] && (map[i][j] < len || len == -1))
				{
					len = map[i][j];
					u = j;
				}
			}
		}
		if (len != -1)
		{
			ans += len;
			visit[u] = true;
			cnt++;
		}
	}
	cout << ans << endl;
}
int main()
{
	int n;
	while (cin >> n)
	{
		memset(map, -1, sizeof(map));
		memset(visit, false, sizeof(visit));
		if (n == 0)
		{
			break;
		}
		char village;		
		int cnt;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> village >> cnt;
			int p = village - 'A';
			for (int i = 0; i < cnt; i++)
			{
				char v2;
				int cost;
				cin >> v2 >> cost;
				int p2 = v2 - 'A';
				map[p][p2] = map[p2][p] = cost;
			}
		}
		Prim(n);
	}
	return 0;
}