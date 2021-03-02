#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 2e3 + 20;

struct cmp
{
    template <typename T, typename U>
    bool operator()(T const &left, U const &right)
    {
        if (left.first == right.first)
            return left.second > right.second;
        else
            return left.first < right.first;
    }
};

int main()
{
    priority_queue<PII, vector<PII>, cmp> n1;
    priority_queue<PII, vector<PII>, cmp> n2;
    priority_queue<PII, vector<PII>, cmp> n3;
    int n;
    while (cin >> n)
    {
        int cnt = 1;
        for(int i = 1;i <= n;i++)
        {
            int num, doc;
            string s;
            cin >> s;
            if(s[0] == 'I')
            {
                cin >> doc >> num;
                if(doc == 1)
                    n1.push({num, cnt++});
                else if(doc == 2)
                    n2.push({num, cnt++});
                else
                    n3.push({num, cnt++});
            }
            else
            {
                cin >> doc;
                if(doc == 1)
                {
                    if(n1.size())
                    {
                        cout << n1.top().second << endl;
                        n1.pop();
                    }
                    else
                        puts("EMPTY");
                }
                else if(doc == 2)
                {
                    if(n2.size())
                    {
                        cout << n2.top().second << endl;
                        n2.pop();
                    }
                    else
                        puts("EMPTY");
                }
                else
                {
                    if(n3.size())
                    {
                        cout << n3.top().second << endl;
                        n3.pop();
                    }
                    else
                        puts("EMPTY");
                }
            }
        }
        while(n1.size())
            n1.pop();
        while(n2.size())
            n2.pop();
        while(n3.size())
            n3.pop();
    }
    return 0;
}