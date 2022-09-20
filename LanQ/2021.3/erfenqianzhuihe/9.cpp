#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 100010;

long long s[N];

int n, k;

long long cnt[N];

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }
    cnt[0] = 1;
    long long res = 0;
    for(int i = 1;i <= n;i++)
    {
        res += cnt[s[i] % k];
        cnt[s[i] % k]++;
    }
    cout << res;
    return 0;
}