#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int a[N];

struct node
{
    int l, r, val;
} t[4 * N];

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (t[p].l == t[p].r)
    {
        t[p].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
}

void uni(int p, int x, int val)
{
    if (t[p].l == t[p].r)
    {
        t[p].val = val;
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid)
        uni(p << 1, x, val);
    else
        uni(p << 1 | 1, x, val);
    t[p].val = max(t[p << 1].val, t[p << 1 | 1].val);
}

int query(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
        return t[p].val;
    int ans = 0;
    int mid = (t[p].l + t[p].r) >> 1;
    if (l <= mid)
        ans = max(ans, query(p << 1, l, r));
    if (r > mid)
        ans = max(ans, query(p << 1 | 1, l, r));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        build(1, 1, n);
        while (m--)
        {
            char C;
            int i, j;
            cin >> C;
            if (C == 'Q')
            {
                cin >> i >> j;
                cout << query(1, i, j) << endl;
            }
            else if (C == 'U')
            {
                cin >> i >> j;
                uni(1, i, j);
            }
        }
    }
    return 0;
}