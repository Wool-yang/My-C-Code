#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;

int h[N], e[N], ne[N], idx, w[N];

int dist[N], level[N];

bool st[N];

int n, m;

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int dijkstra(int level_min, int level_max)
{
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 0});
    while (heap.size())
    {
        PII t = heap.top();
        int ver = t.second, distance = t.first;
        heap.pop();
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            for (int l = 1; l <= n; l++)
            {
                if (level[j] >= level_min && level[j] <= level_max)
                {
                    if (dist[j] > distance + w[i])
                    {
                        dist[j] = distance + w[i];
                        heap.push({dist[j], j});
                    }
                }
            }
        }
    }
    return dist[1];
}

int main()
{
    memset(dist, 0x3f, sizeof dist);
    memset(h, -1, sizeof h);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        int price, c;
        scanf("%d%d%d", &price, &level[i], &c);
        add(0, i, price);
        int t, v;
        for (int j = 1; j <= c; j++)
        {
            scanf("%d%d", &t, &v);
            add(t, i, v);
            add(i, t, v);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = level[1] - m; i <= level[1]; i++)
        ans = min(ans, dijkstra(i, i + m));
    cout << ans << endl;
    return 0;
}