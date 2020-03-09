#include <iostream>

using namespace std;

int main()
{
    int n,t,i,c,j,a[100];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {c=0;
            for(j=0;j<n;j++)
            {
                if(a[i]==a[j])
                    c++;
            }
            if(c%2!=0)
                cout<<a[i]<<" ";
        }cout<<endl;
    }
    return 0;
}
