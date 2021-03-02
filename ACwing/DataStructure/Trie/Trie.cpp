#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int idx = 0, cnt[N], son[N][26];

char str[N];

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

void query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if (!son[p][u])
        {
            cout << 0 <<endl;
            return;
        }
        p = son[p][u];
    }
    cout << cnt[p] <<endl;
    return;
}

int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        char a[2];
        scanf("%s%s", a, str);
        if (a[0] == 'I')
        {
            insert(str);
        }
        else
        {
            query(str);
        }
    }
    return 0;
}