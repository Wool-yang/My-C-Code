#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double max,min,temp,mid=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>temp;
		if(i==1){
			max=temp;
			min=temp;
		}
		else{
			if(max<temp){
				max=temp;
			}
			if(min>temp){
				min=temp;
			}
		}
		if(n%2==0){
			if(i==n/2)
				mid+=temp;
			if(i==n/2+1){
				mid+=temp;
				mid/=2;
			}
		}
		else
		{
			if(i==(n+1)/2)
				mid=temp;
		}
	}
	if(int(mid)!=mid)
		printf("%.f %.1f %.f",max,mid,min);
	else
		printf("%.f %.f %.f",max,mid,min);
	return 0;
} 
