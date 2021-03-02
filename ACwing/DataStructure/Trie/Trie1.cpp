#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 31 * N;

int a[N], son[M][2], idx = 0, n;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            p = son[p][!u];
            res = res * 2 + !u;
        }
        else
        {
            p = son[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}

int main()
{
    int res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        insert(a[i]);
        res = max(res, query(a[i]) ^ a[i]);
    }
    cout << res;
    return 0;
}