#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 30;

int n, m;
int num[N], used[N];

void dfs(int u, int cnt)
{
    if(n - u + cnt < m)
        return;
    if(cnt == m + 1)
    {
        for(int i = 1;i <= m;i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = u;i <= n;i++)
    {
        if(!used[i])
        {
            used[i] = true;
            num[cnt] = i;
            dfs(i + 1, cnt + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}