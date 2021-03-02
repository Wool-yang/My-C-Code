#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, res = 0;
        cin >> x;
        while (x)
        {
            x -= x & -x;
            res++;
        }
        cout << res << " ";
    }
    return 0;
}