#include <iostream>

using namespace std;

const int N = 1010;

int p[N];

int find(int x)
{
    if(p[x] != x)
        return p[x] = find(p[x]);
    return x;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        for(int i = 1;i <= a;i++)
            p[i] = i;
        while(b--)
        {
            int x, y;
            cin >> x >> y;
            p[find(x)] = find(y);
        }
        int ans = 0;
        for(int i = 1;i <= a;i++)
        {
            if(p[i] == i)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}