#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int h[N], ne[M], e[M], idx;

bool st[N];

int ans = N, n = 0;

void add(int a, int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}

int dfs(int u)
{
    st[u] = true;
    int res = 0, sum = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            sum += s;
            res = max(res, s);
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}