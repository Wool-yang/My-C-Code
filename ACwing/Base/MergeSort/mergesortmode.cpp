#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], tem[N], n;

void mergesort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergesort(a, l, mid), mergesort(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
            tem[k++] = a[i++];
        else
            tem[k++] = a[j++];
    }
    while (i <= mid)
        tem[k++] = a[i++];
    while (j <= r)
        tem[k++] = a[j++];
    for (int i = 0; i < k; i++)
        a[l + i] = tem[i];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    mergesort(a, 1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}