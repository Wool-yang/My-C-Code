#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int qu[N], tt = 0, hh = 0;

int main()
{
    int m;
    cin >> m;
    int x;
    while (m--)
    {
        string c;
        cin >> c;
        if (c == "push")
        {
            cin >> x;
            qu[++tt] = x;
        }
        else if (c == "empty")
        {
            if (tt - hh)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else if (c == "pop")
            hh++;
        else
            cout << qu[hh + 1] << endl;
    }
    return 0;
}