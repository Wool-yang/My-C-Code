#include<iostream>

using namespace std;

const int N=100010;

int a[N],b[N];

int main(){
    int n,m,x,c=0;
    cin>>n>>m>>x;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    m--;
    for(int i=0;i<n;i++)
    {
        while(a[i]+b[m]>x)
        {
            m--;
        }
        if(a[i]+b[m]==x)
        {
            cout<<i<<" "<<m;
            c=1;
        }
        if(c)
            break;
    }
    return 0;
}