#include<iostream>
#include<cstdio>
#include<queue>
#include<utility>
#include<cstring>

using namespace std;

const int M = 1e5 + 10;

int n, m, e, f, h;

int tagX, tagY;

int safeX, safeY, R;

int pan[410][410];

int st[410][410];

pair<pair<int, int>, int> player[M];

int dx[8] = {0, 1, -1, 0, 1, -1, -1, 1}, dy[8] = {1, 0, 0, -1, 1, -1, 1, -1};

pair<pair<int, int>, int> bfs(pair<pair<int, int>, int> piii)
{
    queue<pair<pair<int, int>, int>> q;
    q.push(piii);
    pair<int, int> b(0, 0);
    pair<pair<int, int>, int> ans(b, 0);
    while(!q.empty())
    {
        pair<pair<int, int>, int> t = q.front();
        q.pop();
        st[t.first.first][t.first.second] = 1;

        if((t.first.first == tagX && t.first.second == tagY))
        {
            if(ans.second < t.second)
                ans = t;
        }

        for(int i = 0;i < 8;i++)
        {
            int mark = 0;
            if(t.first.first + dx[i] >= 0 && t.first.first + dx[i] < n && t.first.second + dy[i] >= 0 && t.first.second + dy[i] < n)
            {    
                if(!st[t.first.first + dx[i]][t.first.second + dy[i]])
                {
                    if((safeX - t.first.first) * (safeX - t.first.first) + (safeY - t.first.second) * (safeY - t.first.second) > R * R)
                        mark = 1;
                    if((!pan[t.first.first][t.first.second + dy[i]] && !pan[t.first.first + dx[i]][t.first.second] && !pan[t.first.first + dx[i]][t.first.second + dy[i]]) || !mark)
                    {
                        if(mark)
                            t.second--;
                        t.first.first += dx[i];
                        t.first.second += dy[i];
                        q.push(t);
                        st[t.first.first][t.first.second] = 1;
                        //cout << t.first.first << " " << t.first.second << " " << t.second << endl;
                        t.first.first -= dx[i];
                        t.first.second -= dy[i];
                        if(mark)
                            t.second++;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    memset(pan, 0, sizeof(pan));
    scanf("%d%d%d%d%d", &n, &m, &e, &f, &h);
    for(int i = 1;i <= e;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        pan[x][y] = 1;
    }
    for(int i = 1;i <= m;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        player[i].first.first = x;
        player[i].first.second = y;
        player[i].second = h;
    }
    for(int i = 1;i <= f;i++)
    {
        scanf("%d%d%d", &safeX, &safeY, &R);
        for(int j = 1;j <= m;j++)
        {
            
            scanf("%d%d", &tagX, &tagY);
            player[j] = bfs(player[j]);
            memset(st, 0, sizeof(st));
        }
    }
    for(int j = 1;j <= m;j++)
    {
        cout << player[j].second << endl;
    }
    return 0;
}