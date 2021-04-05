#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1e5 + 10;

int num[N];

int main()
{
    int n, q;
    cin >> n >> q;
    for(int i = 0;i < n;i++)
    {
        cin >> num[i];
    }
    while(q--)
    {
        int a;
        cin >> a;
        int l = 0, r = n - 1;

        int mid;
        while(l < r)
        {
            mid = (l + r) >> 1;
            if(num[mid] >= a) r = mid;
            else l = mid + 1;
        }
        if(num[l] != a)
        {
            cout << -1 << " " << -1 << endl;
            continue;
        }
        else
            cout << l << " ";

        l = 0, r = n - 1;
        while(l < r)
        {
            mid = l + r + 1 >> 1;
            if(num[mid] <= a) l = mid;
            else r = mid - 1;
        }
        cout << r << endl;
    }
    return 0;
}