#include <iostream>

using namespace std;

int main()
{
    int i,c=0,j,x[100]={},l=0,w=97,p;char q;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {c=0;
        for(j=i+1;j<s.size();j++)
        {
            if(s[j]==s[i])
                x[i]=++c;
        }
        //cout<<x[i]<<endl;
    }
    for(i=0;i<s.size();i++)
    {
         if(x[i]>l)
        {
            l=x[i];
            p=i;
        }
        if(x[i]==l)
        {
            for(j=0;j<s.size();j++)
            {
                if(((int)s[i])<((int)s[p]))
                    q=s[i];
                else
                    q=s[p];
            }
            else
            {
               for(i=0;i<s.size();i++)
               {
                   if(((int)s[i])<w)
                    q=s[i];
               }
            }
        }
    }
    cout<<q<<" "<<l+1;
    return 0;
}
