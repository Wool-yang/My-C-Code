#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add(int k, int x)
{
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    e[idx++] = x;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    init();
    int m;
    scanf("%d", &m);
    while (m--)
    {
        string c;
        cin >> c;
        if (c == "L")
        {
            int x;
            scanf("%d", &x);
            add(0, x);
        }
        else if (c == "R")
        {
            int x;
            scanf("%d", &x);
            add(l[1], x);
        }
        else if (c == "D")
        {
            int x;
            scanf("%d", &x);
            remove(x + 1);
        }
        else if (c == "IL")
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add(l[k + 1], x);
        }
        else
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << " ";
    }
    return 0;
}