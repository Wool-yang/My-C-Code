#include<iostream>

using namespace std;

int main(){
    double n;
    double l=-10000,r=10000;
    cin>>n;
    while(r-l>1e-8){               // 保险起�?��?�目精度再往后推两位
        double mid=(l+r)/2;
        if(mid*mid*mid>=n) r=mid;
        else l=mid;
    }
    printf("%.6f",l);
    return 0;
}