#include <iostream>
#include <queue>

using namespace std;

unsigned long long bfs(int n)
{
    queue<unsigned long long> q;
    q.push(1);
    while (q.size())
    {
        unsigned long long t = q.front();
        q.pop();
        if (t % n == 0)
            return t;
        else
        {
            q.push(t * 10);
            q.push(t * 10 + 1);
        }
    }
    return 0;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        cout << bfs(n) << endl;
    }
    return 0;
}