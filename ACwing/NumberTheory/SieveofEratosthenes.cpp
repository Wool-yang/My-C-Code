#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, cnt = 0, primes[N];

bool st[N];

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[++cnt]=i;
            for (long long j = (long long int)i * (long long int)i; j <= n; j += i)
                st[j] = true;
        }
    }
    cout << cnt;
    return 0;
}