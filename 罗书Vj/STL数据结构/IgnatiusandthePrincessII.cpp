#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int main()
{
    int a[N];
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            a[i] = i;
        int cnt = 0;
        do
        {
            cnt++;
            if (cnt == m)
                break;
        } while (next_permutation(a + 1, a + n + 1));
        for (int i = 1; i <= n; i++)
            if (i != n)
                cout << a[i] << " ";
            else
                cout << a[i];
        cout << endl;
    }
    return 0;
}