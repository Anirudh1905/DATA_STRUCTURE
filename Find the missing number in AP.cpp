#include <bits/stdc++.h>
using namespace std;

int ap(int *a,int l,int r,int d)
{
    if(r<=l)
        return INT_MAX;
    int mid=l+(r-l)/2;
    if(a[mid+1]-a[mid]!=d)
        return (a[mid]+d);
    if(mid>0 && a[mid]-a[mid-1]!=d)
        return (a[mid-1]+d);
    if(a[mid]==(a[0]+mid*d))
        return ap(a,mid+1,r,d);
    return ap(a,l,mid-1,d);
}
int findmissing(int *a,int n)
{
    int d=(a[n-1]-a[0])/n;
    return ap(a,0,n-1,d);
}
int main()
{
    int a[9]={2,4,8,10,12,14,16,18,20};
    cout<<findmissing(a,9)<<endl;
    return 0;
}
