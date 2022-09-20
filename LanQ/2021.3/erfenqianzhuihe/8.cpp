#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 5010;

int s[N][N];

int n, r;

int x, y;

int main()
{
    scanf("%d%d", &n, &r);
    x = y = r ;
    r = min(5001, r);
    for(int i = 0;i < n;i++)
    {  
        int xi, yi, wi;
        scanf("%d%d%d", &xi, &yi, &wi);
        s[++xi][++yi] += wi;
        x = max(x, xi);
        y = max(y, yi);
    }

    for(int i = 1;i <= x;i++)
        for(int j = 1;j <= y;j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    int ans = 0;
    for(int i = r;i <= x;i++)
    {
        for(int j = r;j <= y;j++)
        {
            ans = max(ans, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
        }
    }
    cout << ans;
    return 0;
}