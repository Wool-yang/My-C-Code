#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int w[N][N], f[N][N];

int t, r, c;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &r, &c);
        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                scanf("%d", &w[i][j]);

        for(int i = 1;i <= r;i++)
            for(int j = 1;j <= c;j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];

        cout << f[r][c] << endl;
    }
    return 0;
}
