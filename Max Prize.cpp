#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,mx=-1,sum=0,k=-1,x;cin>>n;vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    while(a.size()!=0)
    {
        mx=-1;k=-1;
        if(a.size()==1)
        {
            mx=a[0];
            k=0;
        }
        else
        {
            for(int i=0;i<a.size();i++)
            {
                if(i==0)
                    x=a[i]*a[i+1];
                else if(i==a.size()-1)
                    x=a[i]*a[i-1];
                else
                    x=max((a[i]*a[i-1])+a[i+1],(a[i]*a[i+1])+a[i-1]);
                if(x>=mx)
                {
                    if(x==mx && k<a.size() && k>=0)
                    {
                        if(a[i]<a[k])
                            k=i;
                    }
                    else if(x>mx)
                        k=i;
                    mx=x;
                }
                
            }
        }
        sum+=mx;
        a.erase(a.begin()+k);
    }
    cout<<sum;
    return 0;
}
