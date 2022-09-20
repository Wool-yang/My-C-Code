#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10010;

const int INF = 1e8;

int num[N], n;

int main()
{
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n;i++)
        cin >> num[i];
    for(int i = 0;i < n;i++)
    {
        int maxn = -INF, minn = INF;
        for(int j = i;j < n;j++)
        {
            maxn = max(maxn, num[j]);
            minn = min(minn, num[j]);
            if(maxn - minn == j - i)
                ans++;
        }
    }
    cout << ans;
    return 0;
}