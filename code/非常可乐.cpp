#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define SIZE 101
bool visit[SIZE][SIZE][SIZE];
class Node
{
public:
	int x, y, z;
	int t;
	Node(int x, int y, int z, int t)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->t = t;
	}
};
void Pour(int &source, int &des, int capd)
{
	if (capd - des >= source)
	{
		des += source;
		source = 0;
	}
	else
	{
		source -= (capd - des);
		des = capd;		
	}
}
//���ֻ����㵹���ֵĿ���
//�������ݷֱ��ʾԴ������������Ŀ�������������Լ�Ŀ�������ݻ�
int P[6][3] = 
{
	0,1,4,	//��һ���������ڶ���
	0,2,5,	//��һ��������������
	1,0,3,	
	1,2,5,
	2,0,3,
	2,1,4
};
int BFS(int s, int c1, int c2)
{
	memset(visit, false, sizeof(visit));
	queue<Node> q;
	q.push(Node(s, 0, 0, 0));
	visit[s][0][0] = true;
	while (!q.empty())
	{
		Node now = q.front();
		q.pop();
		if (now.x == s / 2 && now.y == s / 2 ||
			now.x == s / 2 && now.z == s / 2 ||
			now.y == s / 2 && now.z == s / 2)
		{
			return now.t;
		}
		for (int i = 0; i < 6; i++)
		{
			//��ǰs��a��b�п��ֵ����Լ����Ե�����
			int nowCap[6] = { now.x, now.y, now.z, s, c1, c2 };
			//��Ԥ�ȶ������ȡ��Դ�����п�������Ŀ�������п������Լ�Ŀ�������ݻ�
			int x = nowCap[P[i][0]];
			int y = nowCap[P[i][1]];
			int z = nowCap[P[i][2]];
			//������
			//cout << nowCap[0] << " " << nowCap[1] << " "<< nowCap[2] << endl;
			Pour(x, y, z);
			//�������������п��ֵ���
			nowCap[P[i][0]] = x;
			nowCap[P[i][1]] = y;
			//cout << nowCap[0] << " " << nowCap[1] << " " << nowCap[2] << endl<<endl;
			x = nowCap[0];
			y = nowCap[1];
			z = nowCap[2];
			if (!visit[x][y][z])
			{
				visit[x][y][z] = true;
				q.push(Node(x, y, z, now.t + 1));
			}

		}
	}
	return -1;
}
int main()
{
	int s, n, m;
	while (cin >> s >> n >> m)
	{
		if (s == n && n == m && m == 0)
		{
			break;
		}
		if (s % 2 == 1)
		{
			cout << "NO" << endl;
			continue;
		}
		int ans = BFS(s, n, m);
		if (ans == -1)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
	return 0;
}