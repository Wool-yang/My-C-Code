#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int a[1005];
int main(){
    memset(a,0,sizeof(a));
    int n,h,max=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&h);
        a[h]++;
        if(max<h)
            max=h;
    }
    int d=0;
    for(int i=max;i>=1;i--){
        if(a[i]!=0){
            if(a[i]>=3){
             printf("%d",i);
              break;
           }
           else{
               d+=a[i];
               if(d>=3){
                  printf("%d",i);
                  break;
              }
          }
        }
    }
    return 0;
}