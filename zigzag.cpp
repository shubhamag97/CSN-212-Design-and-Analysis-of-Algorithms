#include <bits/stdc++.h>
using namespace std;
// let there be t test cases.
// In each test case we get the length of sequence n.
//c[n] is the input array.
//a[i] and b[i] are zigzag sequences ending in ith element and max length for last element with +ve and -ve zigzag.  
// Then we solve it using dp to print the longest length of zig zag sequence.
int main()
{
	int t; cin>>t;
while(t--)
    {int n; cin>>n;
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
        {cin>>c[i];
        a[i] = 1;
        b[i] = 1;
        }
 	int max=1;
    int gmax = 1;
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (c[j] < c[i] && a[i] < a[j] + 1)
                a[i] = a[j] + 1;
 			if( c[j] > c[i] && b[i] < a[j] + 1)
                b[i] = a[j] + 1;
        }
        if(a[i]>b[i])max=a[i];
        else max=b[i];
        if (gmax < max)
            gmax = max;
    }
 
    cout<<gmax<<endl;
    return 0;
}
}
 
