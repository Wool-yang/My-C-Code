#include <iostream>
#include <string>

using namespace std;

const int N = 5e4 + 5;

int a[N];

struct node
{
    int l, r, val;
} t[N << 2];

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

void add(int p, int x, int val)
{
    if (t[p].l == t[p].r)
    {
        t[p].val += val;
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid)
    {
        add(p << 1, x, val);
    }
    else
    {
        add(p << 1 | 1, x, val);
    }
    t[p].val = t[p << 1].val + t[p << 1 | 1].val;
}

int query(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
        return t[p].val;
    int mid = (t[p].l + t[p].r) >> 1;
    int ans = 0;
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
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cout << "Case " << cas << ":\n";
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        build(1, 1, n);
        string s;
        while (cin >> s)
        {
            int i, j;
            if (s == "Add")
            {
                cin >> i >> j;
                add(1, i, j);
            }
            else if (s == "Sub")
            {
                cin >> i >> j;
                add(1, i, -j);
            }
            else if (s == "Query")
            {
                cin >> i >> j;
                cout << query(1, i, j) << endl;
            }
            else
                break;
        }
    }
    return 0;
}