#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>

using namespace std;

const int N = 1e4 + 10;

int num[N];

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    string line;
    getline(cin, line);
    while(n--)
    {
        getline(cin, line);
        stringstream ssin(line);
        while(ssin >> num[cnt])
            cnt++;
    } 
    sort(num, num + cnt);
    
    int ans1 = 0, ans2 = 0;

    for(int i = 1;i < cnt;i++)
    {
        if(num[i] == num[i - 1])
            ans1 = num[i];
        if(num[i] - num[i - 1] >= 2)
            ans2 = num[i] - 1;
    }
    cout << ans2 << " " << ans1;
    return 0;
}