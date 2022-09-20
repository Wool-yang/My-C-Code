#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool dfs(int m, int p, int q)
{
    if(!m) return true;
    if(m >= p && dfs(m - p, p, q)) return true;
    if(m >= q && dfs(m - q, p, q)) return true;
    return false;
}   // Ñ§Ï° y×Ü ±©Á¦

int main()
{
    int p, q;
    cin >> p >> q;
    int ans;
    for(int i = 1;i <= 1000;i++)
    {
        if(!dfs(i, p, q)) ans = i;
    }
    cout << ans;
    return 0;
} 