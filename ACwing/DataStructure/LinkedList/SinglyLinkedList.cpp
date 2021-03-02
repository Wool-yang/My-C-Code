#include <iostream>

using namespace std;

const int N = 100010;

int e[N], en[N], head, idx;

void init()
{
    head = -1;
    idx = 0;
}

void headadd(int x)
{
    en[idx] = head;
    e[idx] = x;
    head = idx++;
}

void add(int k, int x)
{
    en[idx] = en[k];
    e[idx] = x;
    en[k] = idx++;
}

void remove(int k)
{
    en[k] = en[en[k]];
}

int main()
{
    init();
    int m;
    scanf("%d", &m);
    char c;
    while (m--)
    {
        cin >> c;
        if (c == 'H')
        {
            int x;
            scanf("%d", &x);
            headadd(x);
        }
        else if (c == 'D')
        {
            int k;
            scanf("%d", &k);
            if (k == 0)
                head = en[head];
            else
                remove(k - 1);
        }
        else
        {
            int k, x;
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
    }
    int t = head;
    while (t != -1)
    {
        cout << e[t] << " ";
        t = en[t];
    }
    return 0;
}