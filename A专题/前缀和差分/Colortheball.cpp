#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int a[N];

int main()
{
    int n;
    while(cin >> n && n)
    {
        memset(a, 0, sizeof a);
        for(int i = 0;i < n;i++)
        {
            int l, r;
            scanf("%d%d",&l, &r);
            a[l]++;
            a[r + 1]--;
        }
        for(int i = 1;i <= n;i++)
        {
            a[i] += a[i - 1];
            printf("%d",a[i]);
            if(i != n)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}