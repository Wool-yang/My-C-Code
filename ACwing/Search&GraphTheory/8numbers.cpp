#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_map>

using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

string End = "12345678x";

int bfs(string start)
{
    queue<string> q;
    q.push(start);
    unordered_map<string, int> d;
    d[start] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (t == End)
            return d[t];
        int dis = d[t];
        int k = t.find('x');
        int y = k / 3, x = k % 3;
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dx[i], y1 = y + dy[i];
            if (x1 >= 0 && x1 < 3 && y1 >= 0 && y1 < 3)
            {
                swap(t[k], t[x1 + y1 * 3]);
                if (!d.count(t))
                {
                    d[t] = dis + 1;
                    q.push(t);
                }
                swap(t[k], t[x1 + y1 * 3]);
            }
        }
    }
    return -1;
}

int main()
{
    string start;
    for (int i = 0; i < 9; i++)
    {
        char c;
        cin >> c;
        start += c;
    }
    cout << bfs(start) << endl;
    return 0;
}