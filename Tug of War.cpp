#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
int mindif=INT_MAX;
void TOW(int a[],int i,vector<int>s1,vector<int>s2,int sum1,int sum2,int n)
{
    if(i==n)
    {
        int d=abs(sum1-sum2);
        if(d<mindif)
        {
            ans.clear();
            mindif=d;
            ans.push_back(s1);
            ans.push_back(s2);
        }
    }
    if(s1.size()<(n+1)/2)
    {
        s1.push_back(a[i]);
        TOW(a,i+1,s1,s2,sum1+a[i],sum2,n);
        s1.pop_back();
    }
    if(s2.size()<(n+1)/2)
    {
        s2.push_back(a[i]);
        TOW(a,i+1,s1,s2,sum1,sum2+a[i],n);
        s2.pop_back();
    }
}
int main()
{
    ans.clear();int n;cin>>n;int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<int>s1,s2;
    TOW(a,0,s1,s2,0,0,n);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
