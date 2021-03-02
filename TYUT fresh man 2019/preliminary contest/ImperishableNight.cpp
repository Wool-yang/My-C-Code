#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[1000005];
int main(){
    int n,q;
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&q);
    while(q--){
        int l,r,w;
        scanf("%d%d%d",&l,&r,&w);
        a[l]+=w;
        a[r+1]-=w;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        printf("%d",a[i]);
        if(i!=n){
            printf(" ");
        }
    }
    return 0;
}