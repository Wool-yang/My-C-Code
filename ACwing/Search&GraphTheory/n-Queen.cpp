#include <bits/stdc++.h>

using namespace std;

const int N = 20;

bool col[N], dg[N], udg[N];

int n;

char g[N][N];


void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
        {
            puts(g[i]);
        }
        puts("");
        return;
    }
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (!col[i] && !dg[x + i] && !udg[x - i + n])
        {
            g[x][i] = 'Q';
            col[i] = dg[x + i] = udg[x - i + n] = true;
            dfs(x + 1);
            g[x][i] = '.';
            col[i] = dg[x + i] = udg[x - i + n] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}