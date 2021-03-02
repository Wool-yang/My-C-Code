#include<iostream>

using namespace std;

int temp = 0;

int digit(int x)
{
	if(x==0)
	{
		cout<<temp<<endl;
		return 0;
	}
	else if(x==1)
	{
		temp++;
	}
	else if(x==2)
	{
		;	
	} 
	else
	{
		if(x%2==1)
		{
			temp++;
		}
	}
	return digit(x/=2);
}
int main()
{
	int n,x;
	cin>>n;
	while(n!=0)
	{
		cin>>x;
		digit(x);
		temp=0;
		n--;	
	}
	return 0;
} 
