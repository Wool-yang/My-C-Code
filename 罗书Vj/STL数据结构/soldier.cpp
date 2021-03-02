#include <iostream>
#include <list>

using namespace std;

list<int> soldier;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++)
            soldier.push_back(i);
        int flag = 2;
        while (soldier.size() > 3)
        {
            int cnt = 1;
            list<int>::iterator it;
            for (it = soldier.begin(); it != soldier.end();)
            {
                if (cnt++ % flag == 0)
                    it = soldier.erase(it);
                else
                    it++;
            }
            flag == 2 ? flag = 3 : flag = 2;
        }
        list<int>::iterator it;
        for (it = soldier.begin(); it != soldier.end(); it++)
        {
            if (it != soldier.begin())
            {
                cout << " ";
            }
            cout << *it;
        }
        cout << endl;
        soldier.clear();
    }
    return 0;
}