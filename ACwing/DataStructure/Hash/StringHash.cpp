#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e5 + 10, P = 131;

ULL a[N], p[N];
char str[N];

ULL check(int l, int r)
{
    return a[r] - a[l - 1] * p[r - l + 1];
}

int main()
{
    int n, m;
    scanf("%d%d%s", &n, &m, str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        a[i] = a[i - 1] * P + str[i];
    }
    while (m--)
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (check(l1, r1) == check(l2, r2))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}