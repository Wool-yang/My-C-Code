#include <iostream>
#include <cstdio>
using namespace std;

const int N = 25;

int fun[N][N][N];
int digui(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
    {
        return digui(20, 20, 20);
    }
    else if(fun[a][b][c]) return fun[a][b][c];
    else if(a < b && b < c) return fun[a][b][c] = digui(a, b, c - 1) + digui(a, b - 1, c - 1) - digui(a, b - 1, c);
    else return fun[a][b][c] = digui(a - 1, b, c) + digui(a - 1, b - 1, c) + digui(a - 1, b, c - 1) - digui(a - 1, b - 1, c - 1);
}
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c && !(a == -1 && b == -1 && c == -1))
    {
        printf("w(%d, %d, %d) = %d\n", a, b, c, digui(a, b, c));
    }
    return 0;
}