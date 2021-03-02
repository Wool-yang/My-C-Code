#include<iostream>
#include<cstring> 
using namespace std;
int main()
{
	int n,j,x=0;
	char a[11],b[11];
	cin>>a;
	n=strlen(a);
	j=n;
	for(int k=0;k<=n-1;k++)
	{
		b[k]=a[j-1];
		j--;
	}
	j=n;
	for(int i=0;i<=n-1;i++)
	{
		if(b[0]=='0'&&n==1)
			cout<<0;
		else
		{
			if(i==0)
			{
				if(b[j-1]=='-')
				{
					cout<<'-';
				}
				while(b[i]=='0')
				{
					i++;
				}
			}		
			if(b[j-1]=='-'&&i==n-1)
			{
				;
			}
			else
				cout<<b[i];
		}
	}
	return 0;
}
