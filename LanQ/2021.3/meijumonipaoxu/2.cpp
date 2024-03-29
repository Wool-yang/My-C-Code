#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int cnt[N], n, as[N], cs[N], a[N], b[N], c[N], s[N];

int main()
{
    scanf("%d", &n);

    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
        a[i]++;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &b[i]);
        b[i]++;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &c[i]);
        c[i]++;
    }

    for(int i = 1;i <= n;i++)
        cnt[a[i]]++;
    for(int i = 1;i < N;i++)
        s[i] = s[i - 1] + cnt[i];
    
    for(int i = 1;i < n;i++)
        as[i] = s[b[i] - 1];

    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);

    for(int i = 1;i <= n;i++)
        cnt[c[i]]++;
    for(int i = 1;i < N;i++)
        s[i] = s[i - 1] + cnt[i];
    
    for(int i = 1;i < n;i++)
        cs[i] = s[N - 1] - s[b[i]];

    long long res = 0;

    for(int i = 1;i <= n;i++)
        res += (long long)as[i] * cs[i];

    cout << res;
    return 0;
}