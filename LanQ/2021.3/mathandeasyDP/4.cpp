#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 1010;

int n, V;

int w[N], f[N], v[N];

int main()
{
    cin >> n >> V;
    for(int i = 1;i <= n;i++)
        cin >> v[i] >> w[i];
    for(int i = 1;i <= n;i++)
        for(int j = V;j >= v[i];j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[V] << endl;
}