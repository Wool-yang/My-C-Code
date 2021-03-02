#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int st[N], tt = 0;

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
            st[++tt] = x;
        }
        else if (c == "pop")
        {
            tt--;
        }
        else if (c == "empty")
        {
            if (!tt)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << st[tt] << endl;
        }
    }
    return 0;
}