#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int s[MAXN];
void chu()
{
	for(int i=1;i<=MAXN;i++)
		s[i]=i;
}
int cha(int x)
{
	return x==s[x]?x:cha(s[x]);
} 
void bing(int x,int y)
{
	x=cha(x);
	y=cha(y);
	if(x!=y)s[x]=s[y];
} 
int main()
{
	int t,n,m,x,y;
	cin>>t;
	while(t--){
		cin>>n>>m;
		chu();
		for(int i=1;i<=m;i++){
			cin>>x>>y;
			bing(x,y);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i==s[i])
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
