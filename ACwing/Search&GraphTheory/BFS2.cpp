#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx, dis[N];

int n, m;

void add(int a, int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int bfs()
{
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] == -1)
            {
                dis[j] = dis[t] + 1;
                q.push(j);
            }
        }
    }
    return dis[n];
}

int main()
{
    memset(dis, -1, sizeof dis);
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    cout << bfs() << endl;
    return 0;
}