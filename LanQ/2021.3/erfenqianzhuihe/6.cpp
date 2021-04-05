#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;

const int N = 2500010;

struct Sum
{
    int s;
    int c;
    int d;
    bool operator< (const Sum &t)const
    {
        if(t.s != s) return s < t.s;
        if(t.c != c) return c < t.c;
        return d < t.d;
    }
}sum[N];

int main()
{
    cin >> n;
    for(int c = 0;c * c <= n;c++)
    {
        for(int d = c;c * c + d * d <= n;d++)
        {
            sum[m++] = {c * c + d * d, c, d};
        }   
    }
    sort(sum, sum + m);

    for(int a = 0;a * a <= n;a++)
    {
        for(int b = a;b * b + a * a <= n;b++)
        {
            int t = n - a * a - b * b;
            
            int l = 0, r = m - 1;
            while(l < r)
            {
                int mid = l + r>> 1;
                if(sum[mid].s >= t) r = mid;
                else l = mid + 1;
            }

            if(sum[l].s == t)
            {
                printf("%d %d %d %d", a, b, sum[l].c, sum[l].d);
                return 0;
            }
        }
    }
    return 0;
}