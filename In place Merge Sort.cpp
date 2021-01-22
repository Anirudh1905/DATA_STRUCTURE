#include <bits/stdc++.h>
using namespace std;

void merge(int a[],int st1,int m,int r)
{
    int st2=m+1;
    if(a[m]<=a[st2])
        return;
    while(st1<=m && st2<=r)
    {
        if(a[st1]<=a[st2])
            st1++;
        else
        {
            int v=a[st2],i=st2;
            while(i!=st1)
            {
                a[i]=a[i-1];
                i--;
            }
            a[st1]=v;
            m++;
            st2++;
            st1++;
        }
    }
}
void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int a[]={12, 11, 13, 5, 6, 7};
    mergesort(a,0,5);
    for(auto x:a)
        cout<<x<<" ";
    return 0;
}
