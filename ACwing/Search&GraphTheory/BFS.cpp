#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;

int g[N][N], a[N][N];

int hh, tt;

PII q[N * N];

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int bfs()
{
    q[0] = {1, 1};
    memset(a, -1, sizeof a);
    a[1][1] = 0;
    while (hh <= tt)
    {
        auto t = q[hh++];

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x > 0 && y > 0 && x <= n && y <= m && g[x][y] == 0 && a[x][y] == -1)
            {
                a[x][y] = 0;
                g[x][y] = g[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }
    return g[n][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    cout << bfs();
    return 0;
}