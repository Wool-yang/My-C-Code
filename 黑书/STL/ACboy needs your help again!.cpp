#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		stack<int> s;
		queue<int> q;
		int temp, m;
		string str, str1;
		cin >> m >> str;
		if (str == "FIFO")
		{
			for (int i = 1; i <= m; i++)
			{
				cin >> str1;
				if (str1 == "IN")
				{
					cin >> temp;
					q.push(temp);
				}
				else
				{
					if (!q.empty())
					{
						cout << q.front() << endl;
						q.pop();
					}
					else
						cout << "None" << endl;
				}
			}
		}
		else
		{
			for (int i = 1; i <= m; i++)
			{
				cin >> str1;
				if (str1 == "IN")
				{
					cin >> temp;
					s.push(temp);
				}
				else
				{
					if (!s.empty())
					{
						cout << s.top() << endl;
						s.pop();
					}
					else
						cout << "None" << endl;
				}
			}
		}
	}
	return 0;
}
