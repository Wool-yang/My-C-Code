#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m, res, cnt;

int p[N];

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edge[2 * N];

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i] = {a, b, w};
    }
    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(edge, edge + m);
    for (int i = 0; i < m; i++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;
        a = find(a), b = find(b);
        if (a == b)
            continue;
        else
        {
            p[a] = b;
            cnt++;
            res += w;
        }
    }
    if (cnt == n - 1)
        cout << res;
    else
        puts("impossible");
    return 0;
}