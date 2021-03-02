#include<iostream>
#include<algorithm>
using namespace std;
struct tre{
    int shu=0;
    int id;
}app[1001];
bool cmp(tre a,tre b){
    if(a.shu==b.shu)
        return a.id>b.id;
    else
        return a.shu<b.shu;
}
int main(){
    int n,m;
    cin>>n>>m;
    int tm,t=0;
    for(int i=1;i<=n;i++){
        app[i].id=i;
        for(int j=1;j<=m+1;j++){
            cin>>tm;
            t+=tm;
            if(j!=1){
                app[i].shu+=abs(tm);
            }
        }
    }
    sort(app+1,app+1+n,cmp);
    cout<<t<<" "<<app[n].id<<" "<<app[n].shu;
    return 0;

}