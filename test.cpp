#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 5;
const int MOD = 998244353;
LL a[maxn], b[maxn];
LL quick_pow(LL a, LL b)
{
    LL ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans % MOD;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        while (m--)
        {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            if (c == 2)
            {
                a[x]++;
                a[y + 1]--;
            }
            else
            {
                b[x]++;
                b[y + 1]--;
            }
        }
        LL min1 = a[1], min2 = b[1];
        for (int i = 2; i <= n; i++)
        {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
            min1 = min(min1, a[i]);
            min2 = min(min2, b[i]);
        }
        LL sum = quick_pow(2, min1) % MOD * quick_pow(3, min2) % MOD;
        printf("%lld\n", sum);
    }
    return 0;
}