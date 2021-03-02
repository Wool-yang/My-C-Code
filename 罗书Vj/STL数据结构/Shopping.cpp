#include <iostream>
#include <map>

using namespace std;

map<string, int> shop;
int main()
{
    int n, m;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
        }
        cin >> m;
        while (m--)
        {
            int a;
            string s;
            for (int i = 0; i < n; i++)
            {
                cin >> a >> s;
                shop[s] += a;
            }
            map<string, int>::iterator it;
            int res = 1;
            for (it = shop.begin(); it != shop.end(); it++)
            {
                if (it->second > shop["memory"])
                    res++;
            }
            cout << res << endl;
        }
        shop.clear();
    }
    return 0;
}