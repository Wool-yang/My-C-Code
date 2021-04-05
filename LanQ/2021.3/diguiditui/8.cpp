#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

string a, b;

char change(char a)
{
    if(a == '*')
        return 'o';
    return '*';
}

int main()
{
    int ans = 0;
    cin >> a; 
    cin >> b;
    for(int i = 0;i < a.size() - 1;i++)
    {
        if(a[i] != b[i])
        {
            ans++;
            a[i] = change(a[i]);
            a[i + 1] = change(a[i + 1]);
        }
    }
    cout << ans;
    return 0;
}