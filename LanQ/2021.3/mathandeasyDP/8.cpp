#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010, MOD = 100000007;

int n, s, a, b;

int f[N][N];

int get_mod(int x, int y)
{
    return (x + y) % y;
}

int main()
{
    cin >> n >> s >> a >> b;

    f[0][0] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            f[i][j] = (f[i - 1][get_mod(j - i * a, n)] + f[i][j]) % MOD;
            f[i][j] = (f[i - 1][get_mod(j + i * b, n)] + f[i][j]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1;i < n;i++)
    {
        ans = (ans + f[n][i]) % MOD;
    }
    return 0;
}
