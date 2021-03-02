#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 1e4 + 10;

int n, m, k;

int dist[N], backup[N];

struct node
{
    int a, b, w;
} edge[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)
        return -1;
    else
        return dist[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edge[i] = {x, y, z};
    }
    int t = bellman_ford();
    if (t == -1)
        puts("impossible");
    else
        printf("%d", t);
    return 0;
}