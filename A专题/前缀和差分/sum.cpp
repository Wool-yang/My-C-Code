#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 5010;

int vis[N];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis, 0, sizeof vis);
        vis[0] = 1;
        int sum = 0, temp = 0;
        int n, m;
        scanf("%d%d",&n, &m);
        while(n--)
        {
            scanf("%d",&temp);
            sum += temp;
            vis[sum % m]++;
        }
        bool flag = false;
        for(int i = 0;i <= m;i++)
        {
            if(vis[i] >= 2)
            {
                flag = true;
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}