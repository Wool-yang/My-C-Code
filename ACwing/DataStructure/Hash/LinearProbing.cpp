#include <iostream>
#include <cstring>

const int N = 1e5 + 10, null = 0x3f3f3f3f, p = 1e5 + 3;

using namespace std;

int a[N], n;

int find(int x)
{
    int t = (x % p + N) % N;
    while (a[t] != null && a[t] != x)
    {
        if (t == N)
            t = 0;
        t++;
    }
    return t;
}

int main()
{
    memset(a, 0x3f, sizeof a);
    scanf("%d", &n);
    while (n--)
    {
        char c[2];
        int x, k;
        scanf("%s", c);
        scanf("%d", &x);
        k = find(x);
        if (c[0] == 'I')
        {
            a[k] = x;
        }
        else
        {
            if (a[k] != null)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}