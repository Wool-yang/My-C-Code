#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx, w[N];

int n, m;

int dist[N];

bool st[N];

void add(int x, int y, int z)
{
    e[++idx] = y;
    ne[idx] = h[x];
    h[x] = idx;
    w[idx] = z;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    dist[1] = 0;
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int distance = t.first, ver = t.second;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    cout << dijkstra() << endl;
    return 0;
}
