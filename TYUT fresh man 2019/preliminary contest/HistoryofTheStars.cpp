#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
int quickmi(int a, int n)
{
    int base = a;
    int res = 1;
    while (n)
    {
        if (n & 1)
        {
            res *= base;
        }
        base *= base;
        n >>= 1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1;; i++)
    {
        if (n <= (quickmi(2, 2 * i)))
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}