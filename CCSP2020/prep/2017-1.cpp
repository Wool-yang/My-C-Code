#include<iostream>
#include<cstring>

using namespace std;

int lim1[105], lim2[105],get1[105],get2[105];
int n; 

struct pear
{
    int deli;
    int lim;
}p[105];

struct apple
{
    int deli;
    int lim;
}a[105];

void updat(int i, int j)
{   
    get1[i] = 1;
    get2[j] = 1;
    if(a[i].lim != 0)
        lim1[a[i].lim]--;
    if(p[j].lim != 0)
        lim2[p[j].lim - n]--;
}

int compare()
{    
    int maxValue = -1;
    int mi,mj;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(!lim1[i] && !lim2[j] && !get1[i] && !get2[j])
            {
                if((a[i].deli ^ p[j].deli) > maxValue)
                {
                    maxValue = (a[i].deli ^ p[j].deli); 
                    mi = i;
                    mj = j;                 
                }
                else if((a[i].deli ^ p[j].deli) == maxValue)
                {
                    if(a[i].deli > a[mi].deli)
                    {
                        maxValue = (a[i].deli ^ p[j].deli); 
                        mi = i;
                        mj = j;                 
                    }
                    else if(a[i].deli == a[mi].deli)
                        if(i > mi)
                        {
                            maxValue = (a[i].deli ^ p[j].deli); 
                            mi = i;
                            mj = j;                 
                        }
                        else if(i == mi)
                        {
                            if(j > mj)
                            {
                                maxValue = (a[i].deli ^ p[j].deli); 
                                mi = i;
                                mj = j;
                            }                
                        }
                }
            }
        }
    }
    updat(mi, mj);
    return maxValue; 
}

int main()
{
    memset(lim1, 0, sizeof(lim1));
    memset(lim2, 0, sizeof(lim2));
    memset(get1, 0, sizeof(get1));
    memset(get2, 0, sizeof(get2));
    cin >> n;
    for(int i = 1;i <= 2 * n;i++)
    {
        if(i <= n)
            cin >> a[i].deli;
        else
            cin >> p[i - n].deli;
    }
    for(int i = 1;i <= 2 * n;i++)
    {
        if(i <= n)
        {    
            cin >> a[i].lim;
            a[i].lim == 0 ? : lim1[a[i].lim]++;
        }
        else
        {
            cin >> p[i - n].lim;
            if(p[i - n].lim != 0)
                lim2[p[i - n].lim - n]++;
        }
    }
    for(int i = 0;i < n;i++)
    {
        int max = compare();
        cout << max << " ";
    }
    return 0;
}