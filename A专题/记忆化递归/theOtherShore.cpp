#include <iostream>
#include <cstring>

using namespace std;

const int N = 40;

long long int cow1[N];

long long int cow(int n)
{ 
    if(cow1[n] == 0)
        return cow1[n] = cow(n - 1) * 2 + cow(n - 2);
    else
        return cow1[n];
}

int main()
{
    cow1[1] = 3;
    cow1[2] = 9;
    int n;
    cin >> n;
    int m;
    while(n--)
    {
        cin >> m;
        cout << cow(m) << endl;
    }
    return 0;
}