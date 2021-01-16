#include <iostream>
using namespace std;

int main()
{
    int n=5,a[n]={1,2,3,4,5},mx,mn,i=0;
    if(n%2==0)
    {
        if(a[0]>a[1])
        {
            mx=a[0];mn=a[1];
        }
        else
        {
            mx=a[1];mn=a[0];
        }
        i=2;
    }
    else
    {
        mx=a[0];mn=a[0];i=1;
    }
    while(i<n)
    {
        if(a[i]>a[i+1])
        {
            if(a[i]>mx)
                mx=a[i];
            if(a[i+1]<mn)
                mn=a[i+1];
        }
        else
        {
            if(a[i+1]>mx)
                mx=a[i+1];
            if(a[i]<mn)
                mn=a[i];
        }
        i+=2;
    }
    cout<<mn<<" "<<mx;
    return 0;
}
