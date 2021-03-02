#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> PII;

const int N = 100000;

bool st[N + 10];

int bfs(int n, int k)
{
    queue<pair<int, int> > q;
    q.push({n, 0});
    st[n] = true;
    while (q.size())
    {
        int t = q.front().first;
        int t1 = q.front().second;
        q.pop();
        if (t == k)
            return t1;
        else
        {
            if (t + 1 <= N && !st[t + 1] && t < k)
            {
                q.push({t + 1, t1 + 1});
                st[t + 1] = true;
            }
            if (t * 2 <= N && !st[t * 2] && t < k)
            {
                q.push({t * 2, t1 + 1});
                st[t * 2] = true;
            }
            if (t - 1 > 0 && !st[t - 1])
            {
                q.push({t - 1, t1 + 1});
                st[t - 1] = true;
            }
        }
    }
    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << endl;
    return 0;
}