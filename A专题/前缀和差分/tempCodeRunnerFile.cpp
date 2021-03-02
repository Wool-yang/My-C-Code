#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e7 + 10;

bool st[N];

int res[N];

int l, r;

int main()
{
    for (int i = 2; i <= N; i++)
    {
        if (!st[i])
        {
            res[i] = 1;
            for (long long j = (long long int)i * (long long int)i; j <= N; j += i)
                st[j] = true;
        }
    }
    for(int i = 0;i <= N;i++)
        res[i] += res[i - 1];
    while(scanf("%d%d",&l, &r) != EOF)
    {
        if(l != 0)
            cout << res[r] - res[l - 1] << endl << endl;
        else
            cout << res[r] - res[l] << endl << endl;
    }
    return 0;
}