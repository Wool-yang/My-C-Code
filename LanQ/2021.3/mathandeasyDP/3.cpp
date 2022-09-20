#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;


int main()
{
    int ans;
    int gai;
    cin >> gai;
    ans = gai;
    while(gai >= 3)
    {
        ans += gai / 3;
        gai = gai / 3 + gai % 3;
    }
    cout << ans;
    return 0;
}