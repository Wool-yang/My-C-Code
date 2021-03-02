#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 1e5 + 10;

int heap[N], hp[N], ph[N], sz, m;

int n;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
    return;
}

void down(int x)
{
    int t = x;
    if (2 * x <= sz && heap[t] > heap[2 * x])
        t = 2 * x;
    if (2 * x + 1 <= sz && heap[t] > heap[2 * x + 1])
        t = 2 * x + 1;
    if (t != x)
    {
        heap_swap(t, x);
        down(t);
    }
    return;
}

void up(int x)
{
    int t = x;
    if (x / 2 >= 1 && heap[t] < heap[x / 2])
        t = x / 2;
    if (t != x)
    {
        heap_swap(t, x);
        up(t);
    }
    return;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        char a[3];
        int k, x;
        scanf("%s", a);
        if (a[0] == 'I')
        {
            scanf("%d", &heap[++sz]);
            hp[sz] = ++m;
            ph[m] = sz;
            up(sz);
        }
        else if (a[0] == 'P')
            printf("%d\n", heap[1]);
        else if (!strcmp(a, "DM"))
        {
            heap_swap(1, sz);
            sz--;
            down(1);
        }
        else if (a[0] == 'D')
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, sz);
            sz--;
            down(k);
            up(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            heap[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}