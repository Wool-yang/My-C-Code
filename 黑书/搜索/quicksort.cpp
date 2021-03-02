#include <iostream>
#include <cstdio>
#define swap(a, b)    \
	{                 \
		int temp = a; \
		a = b;        \
		b = temp;     \
	}
using namespace std;
int a[10010];
int partition(int left, int right)
{
	int i = left;
	int tep = right;
	for (int j = left; j < right; j++)
	{
		if (a[j] < a[tep])
		{
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[i], a[tep]);
	return i;
}
void quicksort(int left, int right)
{
	if (left < right)
	{
		int i = partition(left, right);
		quicksort(left, i - 1);
		quicksort(i + 1, right);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(1, n);
	for (int i = 1; i <= n; i++)
		printf("%d", a[i]);
	return 0;
}
