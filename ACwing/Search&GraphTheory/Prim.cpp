#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int g[N][N], dist[N];

bool st[N];

int n, m, res = 0;

bool prim()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (dist[t] == 0x3f3f3f3f)
            return false;
        res += dist[t];
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
        st[t] = true;
    }
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    if (prim())
        printf("%d\n", res);
    else
        puts("impossible");
    return 0;
}