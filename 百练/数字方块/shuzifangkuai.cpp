#include<iostream>
using namespace std;
int main()
{
	int n,s=1,ans=0,sum;
	cin>>n;
	for(int j=0;j<=n;j++)
	{
		for(int k=0;k<=n;k++)
		{
			for(int p=0;p<=n;p++)
			{
				if((((j+k)%2==0)&&(k+p)%3==0)&&(j+k+p)%5==0)
				{
					sum=j+k+p;
					if(ans<sum)
						ans=sum;
					s++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
 } 
