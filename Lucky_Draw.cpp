#include <bits/stdc++.h>
using namespace std;
 
int longest(int a[], int n, int o)
{
    int b[n];
    b[0]=a[o];
    int t=0,c=0,f;
    for (int i=o; c<n; i=(i+1)%n)
    {
        if (a[i]<b[0])
            b[0]=a[i];
        else
            if (a[i]>b[t])
            {t++;
             b[t]=a[i];
            }
            else
            {f=(lower_bound(b,b+(t+1),a[i])-b);
                b[f]=a[i];
            }
        c++;}
    t++;
    return t;
}
 
int main()
{int t;cin>>t;
    
    while(t--)
    {
        int n;cin>>n;int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int max=-10000007;
        for(int i=0;i<n;i++)
        {int o=longest(a,n,i);
        if(o>max)max=o;
           }
        cout<<max<<endl;
    }
    return 0;
}
