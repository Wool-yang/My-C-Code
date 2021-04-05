#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    int a = 0, b = 1;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int c = a + b;
        cout << a << " ";
        a = b;
        b = c;
    }
    return 0;
}