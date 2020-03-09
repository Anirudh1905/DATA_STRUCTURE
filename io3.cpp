#include <iostream>

using namespace std;

int main()
{
    int n,s,e,st=0,i,j;
    cin>>n;e=n;
    while(st<e)
    {
        for(i=st;i<e;i++)
        {
            s=s+i;
            if(s==n)
            {
                for(j=st;j<=i;j++)
                {
                    cout<<j<<" ";
                }cout<<"\n";
            }
            else if(s>n)
                break;
        }
        st++;
        s=0;
    }
    return 0;
}
