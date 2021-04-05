#include<iostream>

using namespace std;

const int N = 100010;

int s[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }

    while(m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}
