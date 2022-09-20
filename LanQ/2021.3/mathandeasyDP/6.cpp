#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int f[N], a[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++)
    {
        f[i] = 1;
        for(int j = 1;j < i;j++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    int maxF = 0;
    for(int i = 1;i <= n;i++)
        maxF = max(maxF, f[i]);
    cout << maxF;
    return 0;
}