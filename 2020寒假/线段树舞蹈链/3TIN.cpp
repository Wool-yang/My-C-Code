#include <iostream>
#include <string>

using namespace std;

typedef long long int ll;

const int N = 1e5 + 10;

int a[N];

struct node
{
    ll l, r, val, lazy;
} t[N << 2];

void pushdown(int p, int len)
{
    if (t[p].lazy)
    {
        t[p << 1].lazy = t[p << 1 | 1].lazy = t[p].lazy;
        t[p << 1].val = (len - (len << 1)) * t[p << 1].lazy;
        t[p << 1 | 1].val = (len << 1) * t[p << 1 | 1].lazy;
        t[p].lazy = 0;
    }
}

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].val = a[l];
        t[p].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void add(int p, int x, int x1, int val)
{
    if (x <= t[p].l && t[p].r <= x1)
    {
        t[p].lazy = val;
        t[p].val += val * (t[p].r - t[p].l + 1);
        return;
    }
    pushdown(p, x1 - x + 1);
    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid)
        add(p << 1, x, x1, val);
    if (x1 > mid)
        add(p << 1 | 1, x, x1, val);
    t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

ll query(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
        return t[p].val;
    int mid = (t[p].l + t[p].r) >> 1;
    ll ans = 0;
    if (l <= mid)
        ans += query(p << 1, l, r);
    if (r > mid)
        ans += query(p << 1 | 1, l, r);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (c--)
    {
        char c;
        int a, b, x;
        cin >> c;
        if (c == 'Q')
        {
            cin >> a >> b;
            cout << query(1, a, b) << endl;
        }
        else
        {
            cin >> a >> b >> x;
            add(1, a, b, x);
        }
    }
    return 0;
}