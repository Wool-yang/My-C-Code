#include <stdio.h>
#include <string.h>

#define N 10
int a[N + 1][N + 1];

int app(int m, int n)
{
    if (a[m][n])
        return a[m][n];
    else
    {
        if (m == 1 || n == 1)
            return a[m][n] = 1;
        else if (n > m)
            return a[m][n] = app(m, m);
        else if (n == m)
            return a[m][n] = app(m, n - 1) + 1;
        else
            return a[m][n] = app(m - n, n) + app(m, n - 1);
    }
}

int main(void)
{
    memset(a, 0, sizeof(a));

    int t, m, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);

        printf("%d\n", app(m, n));
    }

    return 0;
}