#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int a[1005][1005],b[1005][1005];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int tem=0,sum=0;
    for(int i=1;i<=q;i++){
        scanf("%d",&tem);
        if(tem==1){
            sum++;
        }
        else{
            sum--;
        }
    }
    if(sum%4>=0){
        for(int i=1;i<=sum%4;i--){
            for(int k=1;k<=n;k++){
                for(int j=1;j<=n;j++){
                    b[k][j]=a[n+1-j][k];
                    printf("%d",b[k][j]);
                    if(j!=n)
                        printf(" ");
                }
            }
        }
    }
    else{
        for(int i=1;i<=-sum%4;i--){
            for(int k=1;k<=n;k++){
                for(int j=1;j<=n;j++){
                    b[k][j]=a[j][n+1-k];
                    printf("%d",b[k][j]);
                    if(j!=n)
                        printf(" ");
                }
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",b[i][j]);
            if(j!=n)
                printf(" ");
        }
        printf("\n");
    }*/
    return 0;
}