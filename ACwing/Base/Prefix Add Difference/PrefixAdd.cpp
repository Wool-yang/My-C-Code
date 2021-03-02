#include <iostream>

using namespace std;

int s[100000];

int main()
{
    int n,m,t;
    cin >> n >> m;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        s[i] += s[i - 1] + t;
    }
    int l,r;
    while (m--)
    {
        scanf("%d%d", &l, &r);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}