#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e4 + 10;

int h[N], e[N], ne[N], w[N], idx, cnt[N];

int n, m, dist[N];

bool st[N];

void add(int a, int b, int c)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    w[idx] = c;
}

bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        st[i] = true;
        q.push(i);
    }
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return false;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    if (spfa())
        puts("No");
    else
        puts("Yes");
    return 0;
}