#include <iostream>
using namespace std;
 int main()
{
    string s;
    int n,i,c;
    cin>>n;
    while(n--)
    {
        int a[26]={};
        cin>>s;c=0;
        for(i=0;i<s.size();i++)
        {
            a[s[i]-97]++;
        }
        for(i=0;i<s.size();i++)
        {
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u')
            {
                if(a[s[i]-97]==1)
                    {c++;}
            }
        }
        if(c%2==0) cout<<"She";
        else cout<<"He";
    }
    return 0;
}
