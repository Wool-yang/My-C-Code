#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int anss[1005000]={0};
int res(int n){
    if(n==1){
        return 1;
    }
    else if(n==0){
        return 1;
    }
    else{
        if(anss[n-1]==0)
            anss[n-1]=res(n-1)%20090909;
        if(anss[n-2]==0)
            anss[n-2]=res(n-2)%20090909;
        return anss[n-1]%20090909+anss[n-2]%20090909;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    cout<<res(n)%20090909;
    return 0;
}