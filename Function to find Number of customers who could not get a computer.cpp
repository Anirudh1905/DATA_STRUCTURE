#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s="GACCBDDBAGEE";int k=3,sum=0,c=0;
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++)
    {
        if(mp.count(s[i])==1)
        {
            sum-=mp[s[i]];
            mp[s[i]]--;
        }
        else
        {
            mp[s[i]]++;
            sum+=mp[s[i]];
            if(sum>k)
                c++;
        }
    }
    cout<<c;
    return 0;
}
