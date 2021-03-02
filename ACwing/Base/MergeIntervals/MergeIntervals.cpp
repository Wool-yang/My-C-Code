#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

vector<PII> a;

int merge(vector<PII> a)
{
    vector<PII> res;
    int st = a[0].first, ed = a[0].second;
    for (auto item : a)
    {
        if (ed < item.first)
        {
            res.push_back({st, ed});
            st = item.first;
        }
        ed = max(ed, item.second);
    }
    res.push_back({st, ed});
    return res.size();
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        a.push_back({l, r});
    }
    sort(a.begin(), a.end());
    printf("%d", merge(a));
    return 0;
}