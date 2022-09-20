#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>

using namespace std;

int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date)
{
    int year = date / 10000;
    int mon = date % 10000 / 100;
    int day = date % 100;
    if(mon < 0 || mon > 12) return false;
    if(mon == 2) 
    {
        int flag = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
        return day > 0 && day <= month[2] + flag;
    }
    if(day > 0 && day <= month[mon]) return true;
    return false;
}

int main()
{
    int date1, date2;
    cin >> date1 >> date2;
    int ans = 0;
    for(int i = 1000;i <= 9999;i++)
    {
        int date = i, temp = i;
        for(int j = 0;j < 4;j++)
        {
            date = date * 10 + temp % 10;
            temp /= 10;
        }
        
        if(date <= date2 && date >= date1 && check(date)) ans++;
    }
    cout << ans;
    return 0;
}