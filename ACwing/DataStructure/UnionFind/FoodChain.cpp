#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

int p[N], d[N];

int find(int x)
{
    if (p[x] == x)
        return p[x];
    int r = find(p[x]);
    d[x] += d[p[x]];
    return p[x] = r;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    int ans = 0;
    while (m--)
    {
        int c, x, y;
        scanf("%d%d%d", &c, &x, &y);
        int px = find(x), py = find(y);
        if (x > n || y > n)
        {
            ans++;
        }
        else
        {
            if (px != py)
            {
                p[px] = py;
                if (c == 1)
                {
                    d[px] = d[y] - d[x];
                }
                else
                {
                    d[px] = d[y] - d[x] + 1;
                }
            }
            else
            {
                if (c == 1)
                {
                    if ((d[x] - d[y]) % 3 != 0)
                        ans++;
                }
                else
                {
                    if (((d[x] - d[y]) % 3 + 3) % 3 != 1)
                        ans++;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}