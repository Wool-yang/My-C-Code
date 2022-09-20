#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 55, MOD = 1000000007;
int n, m, K;

int w[N][N], f[N][N][13][14];

int main()
{
    cin >> n >> m >> K;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            cin >> w[i][j];
            w[i][j]++;
        }
    }

    f[1][1][0][0] = 1;
    f[1][1][1][w[1][1]] = 1;

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            for(int k = 0;k <= K;k++)
            {
                for(int c = 0;c <= 13;c++)
                {
                    int &val = f[i][j][k][c];
                    val = (val + f[i - 1][j][k][c]) % MOD;
                    val = (val + f[i][j - 1][k][c]) % MOD;
                    if(w[i][j] == c)
                    {
                        for(int u = 0;u < c;u++)
                        {
                                val = (val + f[i - 1][j][k - 1][u]) % MOD;
                                val = (val + f[i][j - 1][k - 1][u]) % MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0;i <= 13;i++)
    {
        ans = (ans + f[n][m][K][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}