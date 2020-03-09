#include <iostream>

using namespace std;

int main()
{
    int n,q,a,t,flag;
    cin>>n;
    while(n--)
    {
        cin>>a;q=a;
        t=0,flag=0;
        while(a!=0)
        {
            t=a%100;
            if(t==21)
            {
                flag=1;
                break;
            }
            a=a/10;
        }
        if(q%21==0 || flag==1)
        {
            cout<<"yes";
        }
        else
        {
            cout<<"no";
        }
    }
    return 0;
}
