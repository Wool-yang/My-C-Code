#include<iostream>
#include<queue>
#include<cstdio>
#include<utility>
#include<cstring>

#define PIII pair<pair<int, int>, int>

using namespace std;

char num1[11][11], num2[11][11],st1[11][11],st2[11][11];

int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};

int n, m;

bool bfs1(int x, int y, int T)
{
    if(num1[x][y] == '*')
        return false;
    if(st1[x][y]) return false;
    queue<PIII> q;
    pair<int, int> b(x, y);
    pair<pair<int, int>, int> first(b, T);
    q.push(first);
    st1[first.first.first][first.first.second] = 1;
    while(!q.empty())
    {
        PIII t = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            if(!st1[t.first.first][t.first.second] && ((t.first.first + dx[i] > 0) && (t.first.first + dx[i] < n)) && ((t.first.second + dx[y] > 0) && (t.first.second + dx[y] < m)))
            {
                if(num1[t.first.first + dx[i]][t.first.second + dy[i]] == '.')
                {
                    t.first.first += dx[i];
                    t.first.second += dy[i];
                    t.second--;
                    q.push(t);
                    st1[t.first.first + dx[i]][t.first.second + dy[i]] = 1;
                    t.first.first -= dx[i];
                    t.first.second -= dy[i];
                    t.second++;
                }
                else if(num1[t.first.first + dx[i]][t.first.second + dy[i]] == '#')
                {
                    t.first.first += dx[i];
                    t.first.second += dy[i];
                    t.second--;
                    bool ans = bfs2(t.first.first,t.first.second,t.second);
                    st1[t.first.first + dx[i]][t.first.second + dy[i]] = 1;
                    t.first.first += dx[i];
                    t.first.second += dy[i];
                    t.second++;
                    if(ans) return ans;
                }
                else
                {
                    ;
                }
            }
        }
    }

}

bool bfs2(int x, int y, int T)
{
    if(num2[x][y] == '*')
        return false;
    queue<PIII> q;
    pair<int, int> b(x, y);
    pair<pair<int, int>, int> first(b, T);
    q.push(first);
    st2[first.first.first][first.first.second] = 1;
    while(!q.empty())
    {
        PIII t = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            if(!st2[t.first.first][t.first.second] && ((t.first.first + dx[i] > 0) && (t.first.first + dx[i] < n)) && ((t.first.second + dx[y] > 0) && (t.first.second + dx[y] < m)))
            {
                if(num2[t.first.first + dx[i]][t.first.second + dy[i]] == '.')
                {
                    t.first.first += dx[i];
                    t.first.second += dy[i];
                    q.push(t);
                    st2[t.first.first + dx[i]][t.first.second + dy[i]] = 1;
                    t.first.first -= dx[i];
                    t.first.second -= dy[i];
                }
                else if(num2[t.first.first + dx[i]][t.first.second + dy[i]] == '#')
                {

                }
                else
                {
                    ;
                }
            }
        }
    }

}

int main()
{
    int ti;
    scanf("%d", &ti);
    while(ti--)
    {
        memset(st1, 0, sizeof st1);
        memset(st1, 0, sizeof st2);
        memset(st1, 0, sizeof num1);
        memset(st1, 0, sizeof num2);
        scanf("%d%d", &n, &m);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
            {
                scanf("%c",&num1[i][j]);
            }
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
            {
                scanf("%c",&num1[i][j]);
            }
        
    }
    return 0;
}