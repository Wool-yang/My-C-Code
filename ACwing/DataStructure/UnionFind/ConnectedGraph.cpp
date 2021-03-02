#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N], sz[N];

int find(int x)
{
    if (p[x] != x)
        return p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }
    while (m--)
    {
        char c[3];
        int x, y;
        scanf("%s", c);
        if (c[0] == 'C')
        {
            cin >> x >> y;
            if (find(x) == find(y))
            continue;
            sz[find(x)] += sz[find(y)];
            p[find(y)] = find(x);
        }
        else if (c[1] == '1')
        {
            cin >> x >> y;
            if (find(x) == find(y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> x;
            cout << sz[find(x)] << endl;
        }
    }
    return 0;
}