#include <iostream>

using namespace std;

int main()
{
    int n,c,i,j;
    string s1,s2;
    cin>>n;
    while(n--)
    {
        cin>>s1>>s2;c=0;
        for(i=0;i<s1.size();i++)
        {
            for(j=0;j<s2.size();j++)
            {
                if(s1[i]==s2[j])
                {
                    c++;
                    break;
                }
            }
        }
        if(c==s1.size())
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;
}
