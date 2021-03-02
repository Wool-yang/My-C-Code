#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];

int find(int x)
{
    if (p[x] != x)
        return p[x] = find(p[x]);
    else
        return p[x];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    while (m--)
    {
        char c;
        int x, y;
        cin >> c;
        if (c == 'M')
        {
            cin >> x >> y;
            p[find(x)] = find(y);
        }
        else
        {
            cin >> x >> y;
            if (find(x) == find(y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}