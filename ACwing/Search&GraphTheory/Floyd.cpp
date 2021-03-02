#include<iostream>
#include<cstring>
using namespace std;

const int N = 210;

int a[N][N];

int n, m, Q;

void floyd()
{
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
}

int main()
{
    scanf("%d%d%d",&n, &m, &Q);
    memset(a, 0x3f, sizeof a);
    for(int i = 1;i <= n;i++)
    {
        a[i][i] = 0;
    }
    while(m--)
    {
        int x, y, z;
        scanf("%d%d%d",&x, &y, &z);
            a[x][y] = min(a[x][y], z);
    }
    floyd();
    while(Q--)
    {
        int x, y;
        scanf("%d%d",&x, &y);
        if(a[x][y] > 0x3f3f3f3f / 2)
            printf("impossible\n");
        else
            printf("%d\n",a[x][y]);
    }
    return 0;
}
