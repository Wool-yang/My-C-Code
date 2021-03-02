#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 1e5 + 10;

int n1, n2, m;

int res;

int h[N], e[M], ne[M], idx;

int st[N], match[N];

void add(int a, int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

bool hungary(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == 0 || hungary(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if (hungary(i))
            res++;
    }
    cout << res;
    return 0;
}