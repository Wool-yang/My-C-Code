#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int heap[N], sz;

int n;

void down(int x)
{
    int t = x;
    if (2 * x <= sz && heap[t] > heap[2 * x])
        t = 2 * x;
    if (2 * x + 1 <= sz && heap[t] > heap[2 * x + 1])
        t = 2 * x + 1;
    swap(heap[x], heap[t]);
    if (t != x)
        down(t);
    return;
}

void up(int x)
{
    int t = x;
    if (x / 2 >= 1 && heap[t] < heap[x / 2])
    {
        swap(heap[t], heap[x / 2]);
        t = x / 2;
    }
    if (t != x)
        up(t);
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
            up(sz);
        }
        else if (a[0] == 'P')
            printf("%d\n", heap[1]);
        else if (a == "DM")
        {
            heap[1] = heap[sz];
            sz--;
            down(1);
        }
        else if (a[0] == 'D')
        {
            scanf("%d", &k);
            heap[k] = heap[sz];
            sz--;
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            heap[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}