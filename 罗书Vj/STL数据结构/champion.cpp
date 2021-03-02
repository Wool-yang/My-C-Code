#include <iostream>
#include <set>

using namespace std;

set<string> win;
set<string> lose;

int main()
{
    int n;
    while (cin >> n && n)
    {
        string s1, s2;
        while (n--)
        {
            cin >> s1 >> s2;
            win.insert(s1);
            win.insert(s2);
            lose.insert(s2);
        }
        if (win.size() - lose.size() == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        win.clear();
        lose.clear();
    }
    return 0;
}