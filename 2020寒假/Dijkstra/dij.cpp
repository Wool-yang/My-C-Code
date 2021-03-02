#include <iostream>
#include <string.h>

using namespace std;

const int N = 1e3 + 10;

int g[N][N];
int dis[N], st[N];
int n, m;
int dijistra()
{
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dis[t] > dis[j]))
                t = j;
        st[t] = 1;
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], dis[t] + g[t][j]);
    }
    return dis[n];
}
int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    int a, b, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    cout << dijistra() << endl;
    return 0;
}
