#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;

int cow1[N];

int cow(int n)
{
    if(n == 1 || n == 2 || n == 3)
        return cow1[n] = n;
    else
    {  
        if(cow1[n] == 0)
            return cow1[n] = cow(n - 1) + cow(n - 3);
        else
            return cow1[n];
    }
}

int main()
{
    int n;
    while(cin >> n && n)
    {
        cout << cow(n) << endl;
    }
    return 0;
}