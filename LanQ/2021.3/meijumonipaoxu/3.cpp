#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x)
        {
            int temp = x % 10;
            x /= 10;
            if (temp == 2 || temp == 1 || temp == 0 || temp == 9)
            {
                ans += i;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
