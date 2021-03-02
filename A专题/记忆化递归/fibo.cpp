#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;

int cow1[N];

int cow(int n)
{
    if(n == 1 || n == 2)
        return 1;
    else
    {  
        if(cow1[n] == 0)
            return cow1[n] = cow(n - 1) + cow(n - 2);
        else
            return cow1[n];
    }
}

int main()
{
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