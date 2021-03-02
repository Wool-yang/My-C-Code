#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double n, m, s;
    int cnt = 1;
    while (scanf("%lf%lf%lf", &n, &m, &s) != EOF && !(n == 0 && m == 0 && s == 0))
    {
        double res = 0;
        while (n--)
        {
            double a, b;
            scanf("%lf%lf", &a, &b);
            res += (a * (1 - b / 100.00));

        }
        printf("Case %d: %.2f\n\n",cnt++, res / s);
    }
    return 0;
}