#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], w[N], idx;

int dist[N];

bool st[N];

int n, m;

void add(int a, int b, int c)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    w[idx] = c;
}

int spfa()
{
    queue<int> q;
    q.push(1);
    st[1] = true;
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
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
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
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    int t = spfa();
    if (t == -1)
        puts("impossible");
    else
        printf("%d", t);
    return 0;
}