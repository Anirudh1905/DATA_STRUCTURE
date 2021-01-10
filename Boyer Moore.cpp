#include <bits/stdc++.h>
using namespace std;
#define q 256
void badtable(string s,int m,int bad[q])
{
    for(int i=0;i<q;i++)
        bad[i]=-1;
    for(int i=0;i<m;i++)
        bad[(int)s[i]]=i;
}
void search(string txt,string pat)
{
    int m=pat.size(),n=txt.size(),bad[q],s=0;
    badtable(pat,m,bad);
    while(s<=(n-m))
    {
        int j=m-1;
        while(j>=0 && pat[j]==txt[s+j])
            j--;
        if(j<0)
        {
            cout<<s<<endl;
            s+=(s+m<n)?m-bad[txt[s+m]]:1;
        }
        else
            s+=max(1,j-bad[txt[s+j]]);
    }
}
int main()
{
    search("ABAAABCDABC","ABC");
    return 0;
}
