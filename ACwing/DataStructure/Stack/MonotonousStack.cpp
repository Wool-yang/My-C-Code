#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int st[N], tt = 0;

int main()
{
    int x, m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        while (tt && st[tt] >= x)
            tt--;
        if (tt)
            cout << st[tt];
        else
            cout << -1;
        st[++tt] = x;
        cout << " ";
    }
    return 0;
}