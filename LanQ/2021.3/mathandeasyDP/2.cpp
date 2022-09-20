#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int first;
    cin >> first;
    int left = 0, right = 0;
    for(int i = 0;i < n - 1;i++)
    {
        int x;
        cin >> x;
        if(abs(x) > abs(first) && x < 0) right++;
        if(abs(x) < abs(first) && x > 0) left++;
    }
    int ans = right + left + 1;
    if(first > 0 && right == 0) ans = 1;
    if(first < 0 && left == 0) ans = 1;
    cout << ans; 
    return 0;
}