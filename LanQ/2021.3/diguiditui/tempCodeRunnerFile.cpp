#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

int n;

char g[5][5], backup[5][5];

void turn_1(int x, int y)
{
    if(g[x][y] == '-')
        g[x][y] = '+';
    else
        g[x][y] = '-'; 
}

void turn(int x, int y)
{  
    for(int i = 1;i <= 4;i++)
    {
        turn_1(x, i);
        turn_1(i, y);
    }
    turn_1(x, y);
}

int getXY(int x, int y)
{
    return 4 * (x - 1) + y;
}

int main()
{
    for(int i = 1;i <= 4;i++)
    {
        for(int j = 1;j <= 4;j++)
        {
            cin >> g[i][j];
        }
    }
 
    vector<PII> ans;
    memcpy(backup, g, sizeof g);
    for(int op = 0;op <= 1 << 16 - 1;op++)
    {
        vector<PII> temp;
        for(int i = 1;i <= 4;i++)
        {
            for(int j = 1;j <= 4;j++)
            {
                if(op >> getXY(i, j) & 1)
                {
                    temp.push_back({i, j});
                    turn(i, j);
                }
            }
        }

        bool has_closed = false;
        for(int i = 1;i <= 4;i++)
        {
            for(int j = 1;j <= 4;j++)
            {
                if(g[i][j] == '+')
                    has_closed = true;
            }
        }
        if(!has_closed)
        {
            if(ans.empty() || ans.size() > temp.size())
                ans = temp;
        }
        memcpy(g, backup, sizeof g);
    }
    cout << ans.size() << endl;
    for(int i = 0;i <= ans.size();i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}