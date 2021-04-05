#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = int(1e5) + 10;

int g[N];

int n;

int maxE = 0;

bool check(int mid)
{
    for(int i = 0;i < n;i++)
    {
        mid = 2 * mid - g[i];
        if(mid < 0) return false;
        if(mid >= maxE) return true; 
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d", &g[i]);
        if(maxE < g[i])
            maxE = g[i];
    }
    
    int l = 0, r = 1e5 + 10;
    int mid;
    while(l < r)
    {
        mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }   
    cout << l;
}