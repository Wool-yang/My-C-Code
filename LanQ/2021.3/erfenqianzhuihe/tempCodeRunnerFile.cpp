#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

double n;

bool check(double x)
{
    if(x * x * x < n) 
        return false;
    return true;
}

int main()
{
    cin >> n;
    double x;
    double l = 0, r = n;
    while(r - l > 1e-8)
    {
        double mid = (l + r) / 2 ;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%lf", l);
    return 0;
}