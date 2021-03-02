#include<iostream>
#include<algorithm>
using namespace std;
struct tre{
    int sum;
    int shu=0;
    int l=0;
}app[1001];
int main(){
    int n,m;
    cin>>n;
    int tm;
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>tm;
            if(j==1){
                app[i].sum=tm;
            }
            else{
                if(tm<=0){
                    app[i].sum+=tm;
                }
                else{
                    if(app[i].sum>tm){
                        app[i].sum=tm;
                        app[i].l++;
                    }
                }
            }
        }
    }
    int t=0,d=0,e=0;
    for(int i=1;i<=n;i++){
        t+=app[i].sum;
        if(app[i].l!=0){
            d++;
            if(i==1){
                if(app[2].l&&app[n].l){
                    e++;
                }
            }
            else if(i==n){
                if(app[n-1].l&&app[1].l){
                    e++;
                }
            }
            else{
                if(app[i-1].l&&app[i+1].l){
                    e++;
                }
            }
        }
    }
    cout<<t<<" "<<d<<" "<<e;
}
