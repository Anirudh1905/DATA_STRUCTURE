#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char,pair<int,int>>mp;
    string s="GEEKSFORGEEKS",ans;
    int k=2,c=1,l=3;
    for(int i=0;i<26;i++)
    {
        if(k==7 || k==9)
            l=4;
        else
            l=3;
        if(c>l)
        {
            c=1;
            k++;
        }
        if(c<=l)
        {
            mp.insert({char(i+65),{k,c}});
            c++;
        }
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
            ans+="0";
        else
        {
            for(int j=0;j<mp[s[i]].second;j++)
                ans+=to_string(mp[s[i]].first);
        }
    }
    cout<<ans;
    return 0;
}
