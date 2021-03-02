#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx, d[N], q[N];

int n, m;

int topo()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q[++tt] = i;
    }
    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (d[j] == 0)
                q[++tt] = j;
        }
    }
    return tt == n - 1;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        e[++idx] = y;
        ne[idx] = h[x];
        h[x] = idx;
        d[y]++;
    }
    if (topo())
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", q[i]);
        }
    }
    else
        cout << -1;
    return 0;
}