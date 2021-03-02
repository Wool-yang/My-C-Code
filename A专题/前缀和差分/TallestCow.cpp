#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 10010;

int a[N], s[N];

struct COW
{
    int a, b;
} cow[N];

bool cmp(COW x, COW y)
{
    if (x.a == y.a)
        return x.b < y.b;
    return x.a < y.a;
}

int main()
{
    int n, i, h, r;
    scanf("%d%d%d%d", &n, &i, &h, &r);
    for (int i = 1; i <= n; i++)
        a[i] = h;
    for (int i = 1; i <= r; i++)
    {
        scanf("%d%d", &cow[i].a, &cow[i].b);
        if (cow[i].a > cow[i].b)
            swap(cow[i].a, cow[i].b);
    }
    sort(cow + 1, cow + r + 1, cmp);
    cow[0].a = 0;
    cow[0].b = 0;
    for (int i = 1; i <= r; i++)
    {
        if (!(cow[i].a == cow[i - 1].a && cow[i].b == cow[i - 1].b))
        {
            s[cow[i].a + 1] -= 1;
            s[cow[i].b] += 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] += s[i - 1];
        a[i] += s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
        if (i != n)
            cout << endl;
    }
    return 0;
}