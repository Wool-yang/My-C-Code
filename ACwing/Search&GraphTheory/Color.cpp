#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int h[N], e[N], ne[N], idx;

int n, m;

int st[N];

void add(int a, int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

bool dfs(int x, int color)
{
    st[x] = color;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            if (!dfs(j, 3 - color))
                return false;
        }
        else if (st[j] == color)
            return false;
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
    }
    if (flag)
        puts("Yes");
    else
        puts("No");
    return 0;
}