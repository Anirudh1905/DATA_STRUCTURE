#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[]={1,2,3,4,5,6},k=2,n=6,ans=INT_MAX;
    if(n==1)
        cout<<0;
    else
    {
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            int j=upper_bound(a+i,a+n,k+a[i])-a-1;
            ans=min(ans,n-(j-i+1));
        }
        cout<<ans;
    }
    return 0;
}
