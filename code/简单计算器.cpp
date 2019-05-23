#include <iostream>
#include<string>
#include <stack>
#include <iomanip>
using namespace std;
bool isOp(char str)
{
	if (str == '+' || str == '-' || str == '*' || str == '/')
	{
		return true;
	}
	return false;
}
//����һ���������Ƿ�����������ȼ��Ƿ���ڵڶ��������
bool cmpOP(char op1, char op2)
{
	if (op1 == '/' || op1 == '*')
	{
		if (op2 == '+' || op2 == '-')
		{
			return true;
		}
	}
	return false;
}
bool equalOP(char op1, char op2)
{
	if (op1 == '/' || op1 == '*')
	{
		if (op2 == '/' || op2 == '*')
		{
			return true;
		}
	}
	if (op1 == '-' || op1 == '+')
	{
		if (op2 == '-' || op2 == '+')
		{
			return true;
		}
	}
	return false;
}
double Cal(char op, double n1, double n2)
{
	switch (op)
	{
	case '+':
	{
		return n1 + n2;
		break;
	}
	case '-':
	{
		return n1 - n2;
		break;
	}
	case '*':
	{
		return n1 * n2;
		break;
	}
	case '/':
	{
		return n1 / n2;
		break;
	}
	}
	return -1;
}
string getNum(string content, int index)
{
	string ans = "";
	for (int i = index; i < content.length(); i++)
	{
		if (!isOp(content[i]))
		{
			ans += content[i];
		}
	}
	return ans;
}
int main()
{
	string content;
	while (getline(cin, content))
	{
		if (content == "0")
		{
			break;
		}
		stack<char> op;
		stack<double> num;
		for (int i = 0; i < content.length(); i++)
		{
			//�ո�ֱ���Թ�
			if (content[i] == ' ')
			{
				continue;
			}
			//���������������ֱ����ջ
			if (!isOp(content[i]))		
			{
				string subnum = "";
				for (int j = i; j < content.length(); j++)
				{
					if (!isOp(content[j]))
					{
						subnum += content[j];
						if (j == content.length() - 1)
						{
							i = j;
							break;
						}
					}
					else
					{
						i = j - 1;
						break;
					}
				}
				
				double number = atof(subnum.c_str());
				num.push(number);
				continue;
			}
			//������������
			//�����ջΪ��
			if (op.empty())
			{
				op.push(content[i]);
			}
			else
			{
				char op1 = op.top();
				//ջ����������ȼ����ڻ���ڵ�ǰ�������ʱ
				while ((cmpOP(op1, content[i]) || equalOP(op1, content[i])) && !op.empty() && !num.empty())
				{
					
					//ȡ������ջ������Ԫ��
					double n1 = num.top();
					num.pop();
					double n2 = num.top();
					num.pop();
					double ans = Cal(op1, n2, n1);
					num.push(ans);//�����ջ						
					//cout << n2<<" "<<n1<<" "<<op1<<" "<<ans << endl;
					op.pop();
					if (!op.empty())
					{
						op1 = op.top();
					}
				}
				op.push(content[i]);
			}

		}
		//����ʣ���+������-����
		while (!op.empty() && !num.empty())
		{
			char op1 = op.top();
			//ȡ������ջ������Ԫ��
			double n1 = num.top();
			num.pop();
			double n2 = num.top();
			num.pop();
			double ans = Cal(op1, n2, n1);
			num.push(ans);//�����ջ
			op.pop();
		}
		double ans = num.top();
		num.pop();
		cout << fixed << setprecision(0) << ans << endl;
	}
	return 0;
}