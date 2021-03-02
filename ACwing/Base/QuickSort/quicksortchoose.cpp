#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e6 + 10;

int a[MAXN];
int n, k;

int quicksort(int l, int r, int k)
{
    if (l == r)
        return a[l];
    int x = a[(l + r + 1) / 2], i = l - 1, j = r + 1; //int x=a[(l+r)/2]
    while (i < j)
    {
        while (a[++i] < x);
        while (a[--j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    int sl = i - l; //int sl=j-l+1;
    if (k <= sl)
        return quicksort(l, i - 1, k); //quicksort(l,j,k);
    else
        return quicksort(i, r, k - sl); //quicksort(j+1,r,k-sl);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    cout << quicksort(1, n, k);
    return 0;
}