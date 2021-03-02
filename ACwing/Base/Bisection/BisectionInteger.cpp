#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (q--)
    {
        int l = 0, r = n - 1, x;
        scanf("%d", &x);
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] != x)
            cout << "-1 -1" << endl;
        else
        {
            cout << l << " ";
            int l = 0;
            r = n - 1;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                if (a[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << l << endl;
        }
    }
    return 0;
}
