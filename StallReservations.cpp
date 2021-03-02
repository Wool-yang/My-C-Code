#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=50000+10;
int order[maxn];

struct Node
{
    int st,en,pos;
    friend bool operator<(Node a,Node b)
    {
       if(a.en==b.en)
        return a.st<b.st;
       return a.en>b.en;
    }
}node[maxn];
 
bool cmp(Node a,Node b)
{
    if(a.st==b.st)
        return a.en<b.en;
    else
        return a.st<b.st;
}
 
priority_queue<Node>Q;
 
int main()
{
    int n,ans;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&node[i].st,&node[i].en);
            node[i].pos=i;
        }
        sort(node+1,node+1+n,cmp);
        ans=1;
        Q.push(node[1]);
        order[node[1].pos]=1;
        for(int i=2;i<=n;i++)
        {
            if(!Q.empty()&&Q.top().en<node[i].st)
            {
               order[node[i].pos]=order[Q.top().pos];
               Q.pop();
            }
            else
            {
                ans++;
                order[node[i].pos]=ans;
            }
            Q.push(node[i]);
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            printf("%d\n",order[i]);
        while(!Q.empty())  Q.pop();
    }
    return 0;
}
