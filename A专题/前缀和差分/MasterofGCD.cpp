#include <iostream>
#include <cstring>

using namespace std;

typedef long long int LL;

const int N = 1e5 + 10;

const int INF = 0X3f3f3f3f;

const int mod = 998244353;

LL sum1[N], sum2[N];

int n, m;

LL lowbit(int x)
{
    return x & (-x);
}

void add(int x,LL *C,int k)
{
    while(x <= n)
    {
        C[x] += k;
        x += lowbit(x);
    }
    return;
}

LL suum(int x, LL *C)
{
    LL ans = 0;
    while(x > 0)
    {
        ans += C[x];
        x -= lowbit(x);
    }
    return ans;
}

LL powmod(LL x, LL n)
{
    LL base = x;
    LL result = 1;
    while(n)
    {
        if(n & 1)
        {
            result *= base;
            result %= mod;
        }
        base *= base;
        base %= mod;
        n >>= 1;
    }
    return result % mod;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(sum1, 0, sizeof sum1);
        memset(sum2, 0, sizeof sum2);
        scanf("%d%d",&n, &m);
        for(int i = 0;i < m;i++)
        {
            int l, r, x;
            scanf("%d%d%d",&l, &r, &x);
            if(l > r)
                swap(l, r);
            if(x == 2)
            {
                add(l, sum1, 1);
                add(r + 1, sum1, -1);
            }
            else if(x == 3)
            {
                add(l, sum2, 1);
                add(r + 1, sum2, -1);
            }
        }
        LL min1 = INF, min2 = INF;
        for(int i = 1;i <= n;i++)
        {
            min1 = min(min1, suum(i, sum1));
            min2 = min(min2, suum(i, sum2));
        }
        printf("%lld\n",(powmod(2, min1) * powmod(3, min2)) % mod);
    }
    return 0;
}