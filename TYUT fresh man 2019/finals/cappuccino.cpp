#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(d<b){
        printf("%d",d/a);
    }
    else{
        if(a<double(b)/double(c)){
            printf("%d",d/a);
        }
        else{
            printf("%d",(d/b)*c+(d-(d/b)*b)/a);
        }
    }
    return 0;
}