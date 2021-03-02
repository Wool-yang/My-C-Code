#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1e6+10;

int a[MAXN];
int n;

void quicksort(int a[],int l,int r){
    if(l>=r) return;
    int x=a[(l+r+1)/2],i=l-1,j=r+1;//int x=a[(l+r)/2]
    while(i<j){
        while(a[++i]<x);
        while(a[--j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    quicksort(a,l,i-1);//quicksort(a,l,j);
    quicksort(a,i,r);//quicksort(a,j+1,r);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    quicksort(a,1,n);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    return 0;
}