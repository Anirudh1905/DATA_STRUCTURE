#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n=6,a[n]={5,6,7,9,11,10},k=2,x=11;
    for(int i=0;i<n;)
    {
        if(a[i]==x)
        {
            cout<<i<<endl;break;
        }
        i+=max(1,abs(x-a[i])/k);
    }
    return 0;
}
