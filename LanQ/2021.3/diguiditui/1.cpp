#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int N = 16;

int n;

int num[N];

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0;i < n;i++)
        {
            if(num[i] == 1)
                cout << i + 1 << " "; 
        }
        cout << endl;
        return;
    }

    num[u] = 0;
    dfs(u + 1);

    num[u] = 1;
    dfs(u + 1);
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}