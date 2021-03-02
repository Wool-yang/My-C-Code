#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    char a[4];
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    bool flag = true;
    while (!(a[0] == '0' && a[1] == '0' && a[2] == '0' && a[3] == '0'))
    {
        char st = 'x';
        bool st1 = true;
        if(flag)
            flag = false;
        else
        {
            for (int i = 0; i < 4; i++)
                cin >> a[i];
            if(!(a[0] == '0' && a[1] == '0' && a[2] == '0' && a[3] == '0'))
                printf("\n");
        }
        sort(a, a + 4);
        do
        {
            if (a[0] == '0')
                continue;
            if (st == 'x')
                st = a[0];
            if (a[0] != st)
            {
                st = a[0];
                printf("\n");
                cout << a;
            }
            else if(st1)
            {
                cout << a;
                st1 = false;
            }
            else
                cout << " " << a;
        } while (next_permutation(a, a + 4));
        if(!(a[0] == '0' && a[1] == '0' && a[2] == '0' && a[3] == '0'))
            printf("\n");
    }
    return 0;
}