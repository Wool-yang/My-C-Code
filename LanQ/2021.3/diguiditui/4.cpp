#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 6;

int g[N][N], backup[N][N];

int dx[5] = {-1, 1, 0, 0, 0}, dy[5] = {0, 0, 0, -1, 1};

void turn(int y, int x)
{
    for(int i = 0;i < 5;i++)
    {
        int a = y + dy[i];
        int b = x + dx[i];
        if(a >= 1 && a <= 5 && b >= 1 && b <= 5)
            g[a][b] ^= 1;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        int ans = 10;

        for(int j = 1;j <= 5;j++)
        {
            for(int k = 1;k <= 5;k++)
            {
                g[j][k] = getchar() - 48;
            }
            getchar();
        }

        for(int op = 0;op < 32;op++)
        {
            memcpy(backup, g, sizeof g);
            int step = 0;
            for(int i = 0;i < 5;i++)
            {
                if(op >> i & 1)
                {
                    turn(1, i + 1);
                    step++;
                }
            }

            for(int i = 1;i <= 4;i++)
            {
                for(int j = 1;j <= 5;j++)
                {
                    if(g[i][j] == 0)
                    {
                        turn(i + 1, j);
                        step++;
                    }
                }
            }

            bool hasZero = false;
            for(int i = 1;i <= 5;i++)
            {
                if(g[5][i] == 0)
                {
                    hasZero = true;
                    break;
                }
            }
            
            if(!hasZero)
                ans = min(ans, step);
            memcpy(g, backup, sizeof g);
        }
        
        if(ans > 6) ans = -1;

        cout << ans << endl;
        getchar();
    }    
    return 0;
}


/* #include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 6;

char g[N][N], backup[N][N];

int dx[5] = {-1, 1, 0, 0, 0}, dy[5] = {0, 0, 0, -1, 1};

void turn(int y, int x)
{
    for(int i = 0;i < 5;i++)
    {
        int a = y + dy[i];
        int b = x + dx[i];
        if(a >= 0 && a < 5 && b >= 0 && b < 5)
            g[a][b] ^= 1;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int ans = 10;

        for(int j = 0;j < 5;j++)
        {
            cin >> g[j];
        }

        for(int op = 0;op < 32;op++)
        {
            memcpy(backup, g, sizeof g);
            int step = 0;
            for(int i = 0;i < 5;i++)
            {
                if(op >> i & 1)
                {
                    turn(0, i);
                    step++;
                }
            }

            for(int i = 0;i < 4;i++)
            {
                for(int j = 0;j < 5;j++)
                {
                    if(g[i][j] == '0')
                    {
                        turn(i + 1, j);
                        step++;
                    }
                }
            }

            bool hasZero = false;
            for(int i = 0;i < 5;i++)
            {
                if(g[4][i] == '0')
                {
                    hasZero = true;
                    break;
                }
            }
            
            if(!hasZero)
                ans = min(ans, step);
            memcpy(g, backup, sizeof g);
        }
        
        if(ans > 6) ans = -1;

        cout << ans << endl;
    }    
    return 0;
} */