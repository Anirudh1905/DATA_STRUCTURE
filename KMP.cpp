#include <bits/stdc++.h>
using namespace std;
void computelps(string pat,int m,int* lps)
{
    int l=0,i=1;
    while(i<m)
    {
        if(pat[l]==pat[i])
        {
            l++;
            lps[i]=l;
            i++;
        }
        else
        {
            if(l!=0)
                l=lps[l-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
void KMPsearch(string pat,string txt)
{
    int m=pat.size(),n=txt.size(),lps[m]={0},i=0,j=0;
    computelps(pat,m,lps);
    while(i<n)
    {
        if(txt[i]==pat[j])
        {
            i++;j++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
        if(j==m)
            cout<<i-j;
    }
}
int main()
{
    string pat="ABABCABAB",txt="ABABDABACDABABCABAB";
    KMPsearch(pat,txt);
    return 0;
}
