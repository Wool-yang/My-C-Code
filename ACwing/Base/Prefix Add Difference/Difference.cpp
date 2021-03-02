#include<iostream>
#include<cstring>

using namespace std;

const int N=100010;
int a[N],b[N];

int main(){
    memset(b,0,sizeof(b));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    while(m--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        b[l]+=c;
        b[r+1]-=c;
    }
    for(int i=1;i<=n;i++){
        b[i]+=b[i-1];
        a[i]+=b[i];
        cout<<a[i]<<" ";
    }
    return 0;
}