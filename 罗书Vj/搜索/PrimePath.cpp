#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 10000;

bool vis[N + 100], pri[N + 100];

int turn(int x, int k)
{
    int t = x;
    for (int i = 1; i < k; i++)
        t /= 10;
    t %= 10;
    for (int i = 1; i < k; i++)
        t *= 10;
    return x - t;
}

void prime()
{
    for (int i = 2; i < N; i++)
    {
        if (!pri[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                pri[j] = true;
            }
        }
    }
}

int bfs(int x, int y)
{
    memset(vis, false, sizeof vis);
    vis[x] = true;
    queue<PII> q;
    q.push({x, 1});
    while (q.size())
    {
        int a = q.front().first, b = q.front().second;
        q.pop();
        if (a == y)
            return b - 1;
        int t = 1000;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j <= 9; j++)
            {
                int c = turn(a, 4 - i);
                if (i == 0 && j == 0)
                    continue;
                c += t * j;
                if (!pri[c] && !vis[c])
                {
                    q.push({c, b + 1});
                    vis[c] = true;
                }
            }
            t /= 10;
        }
    }
    return -1;
}

int main()
{
    prime();
    int n, x, y;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        int t = bfs(x, y);
        t == -1 ? cout << "Impossible" << endl : cout << t << endl;
    }
    return 0;
}