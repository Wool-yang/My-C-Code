#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<double>x;
	char c;
	double n;
	while(1){
		double temp;
		cin>>n;
		c=getchar();
        if (n==0&&c=='\n') 
            break;
		else{
			x.push(n);
			while(cin>>c>>n){
				if(c=='*'){
					temp=x.top()*n;
					x.pop();
					x.push(temp);
				}
				else if(c=='/'){
					temp=x.top()/n;
					x.pop();
					x.push(temp);
				}
				else if(c=='+'){
					x.push(n);
				}
				else
					x.push(-n);
				if(getchar()=='\n')
					break;
			}
			double ans=0;
			while(!x.empty()){
				ans+=x.top();
				x.pop();
			}
			printf("%.2lf\n",ans);
		}
	}
	return 0;
}
