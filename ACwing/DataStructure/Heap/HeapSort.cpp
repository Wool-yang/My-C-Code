#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], sz;

int n, m;

void down(int x)
{
    int t = x;
    if (2 * x <= sz && a[t] > a[2 * x])
        t = 2 * x;
    if (2 * x + 1 <= sz && a[t] > a[2 * x + 1])
        t = 2 * x + 1;
    swap(a[t], a[x]);
    if (x != t)
        down(t);
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    sz = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = n / 2; i; i--)
        down(i);
    while (m--)
    {
        printf("%d ", a[1]);
        a[1] = a[sz];
        sz--;
        down(1);
    }
    return 0;
}