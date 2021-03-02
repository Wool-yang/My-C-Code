#include <bits/stdc++.h>
using namespace std;
int main()
{
	stack<char> s;
	int n;
	scanf("%d", &n);
	getchar();
	char ch;
	while (n--)
	{
		while (true)
		{
			ch = getchar();
			if (ch == ' ' || ch == '\n' || ch == EOF)
			{
				while (!s.empty())
				{
					printf("%c", s.top());
					s.pop();
				}
				if (ch == '\n' || ch == EOF)
					break;
				printf(" ");
			}
			else
				s.push(ch);
		}
		printf("\n");
	}
	return 0;
}
