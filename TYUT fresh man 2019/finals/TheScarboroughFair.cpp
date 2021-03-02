#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double a,b,c,w;
    scanf("%d%lf%lf%lf",&n,&a,&b,&c);
    int t,ans=0;
    for(int i=1;i<=n;i++){
        scanf("%d%lf",&t,&w);
        if(t==1){
            if(w>=a){
                if((w-a)<=c/2){
                    c-=(w-a)*2;
                    a=0;
                }
                else if(c>1&&(w-a-c/2)<=b/4){
                    b-=(w-a-c/2)*4;
                    c=0;
                    a=0;
                }
                else if((w-a)<=b/4){
                    b-=(w-a)*4;
                    a=0;
                }
                else{
                    ans++;
                    break;
                }
            }
            else{
                a-=w;
            }
        }
        else if(t==2){
            if(w>=b){
                if((w-b)<=a/2){
                    a-=(w-b)*2;
                    b=0;
                }
                else if(a>1&&(w-b-a/2)<=c/4){
                    c-=(w-b-a/2)*4;
                    b=0;
                    a=0;
                }
                else if((w-b)<=c/4){
                    c-=(w-b)*4;
                    b=0;
                }
                else{
                    ans++;
                    break;
                }
            }
            else{
                b-=w;
            }
        }
        else if(t==3){
            if(w>=c){
                if((w-c)<=b/2){
                    b-=(w-c)*2;
                    c=0;
                }
                else if(b>1&&(w-c-b/2)<=a/4){
                    a-=(w-c-b/2)*4;
                    c=0;
                    b=0;
                }
                else if((w-c)<=a/4){
                    a-=(w-c)*4;
                    c=0;
                }
                else{
                    ans++;
                    break;
                }
            }
            else{
                c-=w;
            }
        }
    }
    printf("%lf%lf%lf",a,b,c);
    if(!ans){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}