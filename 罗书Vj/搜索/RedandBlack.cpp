#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 25;

char a[N][N];

bool b[N][N];

int dat[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};

int n, m;

int cnt;

void bfs(int x, int y)
{
    memset(b, false, sizeof b);
    queue<PII> q;
    q.push({x, y});
    b[x][y] = true;
    while (q.size())
    {
        int x1 = q.front().first;
        int y1 = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x2 = x1 + dat[i][0];
            int y2 = y1 + dat[i][1];
            if ((x2 >= 1 && x2 <= m) && (y2 >= 1 && y2 <= n))
            {
                if (!b[x2][y2])
                {
                    if (a[x2][y2] == '.')
                    {
                        q.push({x2, y2});
                        cnt++;
                        b[x2][y2] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    int x, y;
    while (cin >> n >> m && (n != 0 && m != 0))
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
            }
        }
        bfs(x, y);
        cout << cnt + 1 << endl;
        cnt = 0;
    }
    return 0;
}