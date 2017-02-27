
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; t=1;
	while(t--)
	{
	int w,d;string s;cin>>w>>d;
	getline(cin,s);
	getline(cin,s);
	long long int dp[w+1][d+1];
	
	for(int i=0;i<=w;i++)
	for(int j=0;j<=d;j++)dp[i][j]=1;
	
		
		int o=s.size();
	for(int i=2;i<o;i+=10)
	{if(s[i]=='"')i++;
	 if(s[i]==s[i+4])
	 {int a1=s[i+2]-'0',c1=s[i+6]-'0';
	 if(a1>c1){int t1=a1;a1=c1;c1=t1;}
	 for(int k=a1+1;k<c1+1;k++)
	 {dp[s[i]-'0'][k]=-1;}
	}
	else if(s[i+2]==s[i+6])
	 {int a1=s[i]-'0',c1=s[i+4]-'0';
	 if(a1>c1){int t1=a1;a1=c1;c1=t1;}
	 for(int k=a1+1;k<c1+1;k++)
	 {dp[k][s[i+2]-'0']=-2;}
	}
	}
	
	for(int i=0;i<=w;i++)
	{for(int j=0;j<=d;j++)
	{if(i==0){
	if((dp[i][j]!=-1&&dp[i][j]!=-2)&&j!=0)dp[i][j]=dp[i][j-1];
	else if(j!=0)dp[i][j]=0;
	}
	else if(j==0)
	{
	if((dp[i][j]!=-1&&dp[i][j]!=-2)&&i!=0)dp[i][j]=dp[i-1][j];
	else if(i!=0) dp[i][j]=0;
	}
	else{
	if(dp[i][j]!=-1&&dp[i][j]!=-2)dp[i][j]=dp[i-1][j]+dp[i][j-1];
	else if(dp[i][j]==-1){
	dp[i][j]=dp[i-1][j];}
	else {
	dp[i][j]=dp[i][j-1];}
	}
	}
	}
	dp[0][0]=0;
	cout<<dp[w][d]<<endl;
	}
	return 0;

}
