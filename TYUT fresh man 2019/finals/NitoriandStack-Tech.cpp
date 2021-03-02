#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char a[30],b[30];
    int n,ans1=0,ans=0;
    scanf("%d",&n);
    scanf("%s",&a);
    scanf("%s",&b);
    for(int i=0;i<n;i++){
        if(a[i]==b[i]){
            ;
        }
        else{
            ans1++;
            int tem=0;
            for(int j=n-1-i;;j--){
                cout<<a[i]<<b[i+j];
                if(a[i]==b[i+j]){
                    ans++;
                    break;
                }
            }
            i=i+tem;
        }
    }
    cout<<ans1<<" "<<ans<<endl;
    if(ans1==ans){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}