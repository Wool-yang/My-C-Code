#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n, path[N];

bool a[N];

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        puts("");
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (!a[i])
            {
                path[x] = i;
                a[i] = true;
                dfs(x + 1);
                path[x] = 0;
                a[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}