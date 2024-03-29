#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, k;

int h[N], w[N];

bool check(int x)
{
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        ans += (h[i]/x) * (w[i]/x); 
        if(ans >= k)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 0;i < n;i++)
        scanf("%d%d", &h[i], &w[i]);
    
    int l = 1, r = 1e5;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
    return 0;
}