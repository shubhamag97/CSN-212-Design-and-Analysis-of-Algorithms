#include <iostream>
using namespace std;
int dir(int x1,int y1, int x2, int y2, int x3, int y3)
{
int o=(y2-y1)*(x3-x2)-(y3-y2)*(x2-x1);
if(o==0)return 0;
return o>0? 1:-1;
}
//0--> same line
//1--> clockwise
//-1--> counterclockwise
int main() {
	int n;cin>>n;
	if(n<3){cout<<"already convex hull"<<endl;return 0;}
	int a[n][2],l=0;
	for(int i=0;i<n;i++)
	{
	cin>>a[i][0]>>a[i][1];
	if(a[l][0]>a[i][0])l=i;
	}
	// five n then n x and y coordinates as input
	int b=l,c;
	do{
	cout<<"("<<a[b][0]<<","<<a[b][1]<<")"<<endl;//print point
	c=(b+1)%n;//next point
	for(int i=0;i<n;i++)
	{
	if(dir(a[b][0],a[b][1],a[i][0],a[i][1],a[c][0],a[c][1])==-1)
	{c=i;}// check if most counterclockwise or not and adjust accordingly.
	}
	b=c;
	
	}while(b!=l);// check if polygon complete or not
	return 0;
}
