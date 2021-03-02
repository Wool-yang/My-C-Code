#include <iostream>
#include <algorithm>

using namespace std;

long long dp[3], cnt, k;

long long n, x, zero = 0;

int main()
{
    scanf("%lld%lld", &n, &x);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&k);
        dp[0] = max(zero, dp[0] + k);
        dp[1] = max(dp[0], dp[1] + k * x);
        dp[2] = max(dp[1], dp[2] + k);
        cnt = max(cnt, dp[2]);
    }
    printf("%lld",cnt);
    return 0;
}