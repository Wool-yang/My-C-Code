#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;
int main()
{
	int n,i=0;
	char a[21],b[21];
	while(cin.getline(a,21))
	{
		n=strlen(a);
		for(int k=0;k<=n-1;k++)
		{
			if(a[k]>='0'&&a[k]<='9')
			{
				b[i]=a[k];
				i++;
			}
		}
		b[i]='\0';
		sort(b,b+i);
		for(int j=0;j<i;j++)
		{
			cout<<setw(4)<<b[j];
		}
		i=0;
		cout<<endl;
	}
	return 0;
}
