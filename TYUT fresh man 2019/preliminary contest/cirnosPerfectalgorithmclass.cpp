#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
using namespace std;
int main(){
    int a[105],b[105];
    int n,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    for(int tem=1;tem!=0;){
    	tem=0;
        for(int i=1;i<=n;i++){
            if(i!=n){
                if(a[i]>a[i+1]){
                    swap(a[i],a[i+1]);
                    ans++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                tem++;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}