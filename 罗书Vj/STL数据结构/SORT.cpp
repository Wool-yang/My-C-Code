#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int a[N];

int main()
{
    int n, m;

    while(scanf("%d%d",&n, &m) != EOF)
    {
        for(int i = 0;i < n;i++)
        {
            int t;
            scanf("%d",&t);
            a[t + 500000] = 1;
        }
        for(int i = N;m > 0;i--)
        {
            if(a[i])
            {
                if(m != 1)
                    cout << i - 500000 << " ";
                else
                    cout << i - 500000 << endl;
                m--;
            }
        }
    }
    return 0;
}