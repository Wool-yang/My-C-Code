#include <iostream>
#include <cstring>

const int N = 1e5 + 10, p = 1e5 + 3;

using namespace std;

int h[N], e[N], ne[N], idx, n;

bool find(int x)
{
    int t = (x % p + N) % N;
    for (int i = h[t]; i != -1; i = ne[i])
    {
        if (e[i] == x)
            return true;
    }
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    while (n--)
    {
        char c[2];
        int x;
        scanf("%s", c);
        scanf("%d", &x);
        if (c[0] == 'I')
        {
            int t = (x % p + N) % N;
            e[++idx] = x;
            ne[idx] = h[t];
            h[t] = idx;
        }
        else
        {
            if (find(x))
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}