#include<iostream>

using namespace std;

typedef long long LL;

const int N=1e6+10;

int a[N],tem[N],n;

LL mergesort(int l,int r){
    if(l>=r) return 0;
    int mid=(l+r)/2;
    LL res=mergesort(l,mid)+mergesort(mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]) tem[k++]=a[i++];
        else{
            tem[k++]=a[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid) tem[k++]=a[i++];
    while(j<=r) tem[k++]=a[j++];
    for(int i=0;i<k;i++) a[l+i]=tem[i];
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%lld",mergesort(1,n));
    return 0;
}