#include<iostream>

using namespace std;

const int N=100010;

int a[N],s[N];

int main(){
    int res=0,n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        while(s[a[i]]>1){
            s[a[j]]--;
            j++;
        }
        res=max(res,i-j+1);
    } 
    cout<<res;
    return 0;
}