#include <iostream>

using namespace std;

const int N = 1e8 + 10;

int primes[N], n, cnt = 0;

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (!primes[i])
            primes[++cnt] = i;
        for (int j = 1; i * primes[j] <= n; j++)
        {
            primes[i * primes[j]] = 1;
            if (i % primes[j] == 0)
                break;
        }
    }
    for (int j = 1; j <= cnt; j++)
    {
        cout << primes[j] << " ";
    }
    cout << endl << cnt;
    return 0;
}