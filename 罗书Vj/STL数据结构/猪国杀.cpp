#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e3 + 10;

int n, m, fnum, idx;

bool mp = true;

queue<char> card;

struct pigg
{
    int heal, cardnum;
    char card[N];
    int ncard,lcard;
    char id[3];
    bool aa[11];
    bool enuip;
    int next, last;
    int ac[11];
} a[11];

void touchcard(int x)
{
    a[x].cardnum++;
    a[x].card[a[x].cardnum] = card.front();
    card.pop();
}

void kill(int x)
{
    if(a[x].aa[a[x].next])
    {
        for(int i = 1;i <= a[a[x].next].cardnum;i)
            a[a[x].next]
    }
}

void wjqf()
{

}

void nmrq()
{

}

void jd()
{

}

bool js()
{

}

void fight()
{
    for (int i = 1; i <= n; i++)
    {
        if(a[i].heal <= 0)  continue;
        else
        {    
            for (int j = 1; j <= a[i].cardnum; j++)
            {
                if(a[i].card[j] == 'x')
                    continue;
                if (a[i].card[j] == 'P')
                {
                    if(a[i].heal < 4)
                    { 
                        a[i].card[j] = 'x';
                        a[i].heal++;
                    }
                }
                if (a[i].card[j] == 'K')
                {
                    a[i].card[j] = 'x';
                    kill(i);
                }
                if(a)
            }
        }
    }
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        a[i].next = i + 1;
        a[i].last = i - 1;
        if(a[i].id[0] == 'F' && a[a[i].next].id[0] == 'M')  a[i].aa[a[i].next] = true;
        else a[i].aa[a[i].next] = false;
        if(a[i].id[0] == 'F' && a[a[i].last].id[0] == 'M')  a[i].aa[a[i].last] = true;
        else a[i].aa[a[i].last] = false;
    }
    a[1].last = n, a[n].next = 1;
    if(a[1].id[0] == 'F' && a[n].id[0] == 'M')  a[1].aa[n] = true;
    else a[1].aa[n] = false;
    if(a[n].id[0] == 'F' && a[1].id[0] == 'M')  a[n].aa[1] = true;
    else a[n].aa[1] = false;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", a[i].id);
        a[i].cardnum = 4;
        a[i].heal = 4;
        for (int j = 1; j <= 4; j++)
            scanf("%s", &a[i].card[j]);
    }
    for (int i = 1; i <= m; i++)
    {
        char temp;
        cin >> temp;
        card.push(temp);
    }
    for (int i = 1; i <= n; i++)
        if (a[i].id[0] == 'F')
            fnum++;
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    return 0;
}