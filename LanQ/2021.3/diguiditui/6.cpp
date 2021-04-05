#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;

int ans;

bool used[10], chec[10];

const int N = 1e6 + 10;

bool check(int a, int c)
{
    long long b = (long long)n * c - a * c;

    if(!a || !b || !c) return false;

    memcpy(chec, used, sizeof used);
    while(b)
    {
        int temp = b % 10;
        b = b / 10;
        if(!temp || chec[temp])
            return false;
        else
            chec[temp] = true;
    }
    bool x = true;
    for(int i = 1;i <= 9;i++)
        if(!chec[i])
            x = false;
    return x;
}

void dfsC(int a, int c, int u)
{
    if(u > 9) return;

    if(check(a, c)) ans++;
    for(int i = 1;i <= 9;i++)
    {
        if(!used[i])
        {
            used[i] = true;
            dfsC(a, c * 10 + i, u + 1);
            used[i] = false;
        }
    }
}

void dfsA(int u, int a)
{
    if(a >= n) return;
    if(a) dfsC(a, 0, u);
    for(int i = 1;i <= 9;i++)
    {
        if(!used[i])
        {
            used[i] = true;
            dfsA(u + 1, a * 10 + i);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfsA(0, 0);
    cout << ans << endl;
    return 0;
}