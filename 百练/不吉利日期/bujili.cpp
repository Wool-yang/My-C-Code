#include<iostream>
using namespace std;
int main()
{
	int w,ans,k;
	cin>>k;
	for(int l=1;l<=31;l++)
	{
		a[l]=l;
	}
	for(int i=1;i<=12;i++)
	{
		if((((i==1||i==3)||(i==5||i==7))||((i==8)||(i==10)))||(i==12))
		{
			for(int j=1;j<=31;j++)
			{
				if(j==13&&k==5)
				ans
					k++;
				if(k==8)
					k=1;
			}
		}
		else if(i==2)
		{
			for(int j=1;j<=28;j++)
			{
				if(j==13&&k==5)
				cout<<i<<endl;
					k++;
				if(k==8)
					k=1;
			}
		}
		else
		{
			for(int j=1;j<=30;j++)
			{
				if(j==13&&k==5)
				cout<<i<<endl;
					k++;
				if(k==8)
					k=1;
			}
		}
	}
	return 0;
}
