#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 12;

int num[N];

bool used[N];

int n;

void dfs(int u)
{
    if(u == n + 1)
    {
        for(int i = 1;i <= n;i++)
        {
            cout << num[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!used[i])
        {
            used[i] = true;
            num[u] = i;
            dfs(u + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}