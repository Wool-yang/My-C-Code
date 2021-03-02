#include<iostream>

using namespace std;

const int N=100010;

int a[N],b[N];

int main(){
    int n,m,x;
    cin>>n>>m>>x;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    while(a[n--]>x);
    while(b[m--]>x);
    for(;n>=0&&m>=0;)
    {
        if(a[n]+b[m]>x)
        {
            if(a[n]>b[m])
            {
                n--;
            }
            else
            {
                m--;   
            }
        }
        if(a[n]+b[m]==x){
            break;
        }
    }
    cout<<n<<" "<<m;
    return 0;
}