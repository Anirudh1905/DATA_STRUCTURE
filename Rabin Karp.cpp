#include <bits/stdc++.h>
#define d 256
using namespace std;
void search(string txt,string pat,int q)
{
    int m=pat.size(),n=txt.size(),h=pow(d,m-1),p=0,t=0,j=0;
    h=h%q;
    for(int i=0;i<m;i++)
    {
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
    for(int i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(txt[i+j]!=pat[j])
                    break;
            }
            if(j==m)
                cout<<i<<endl;
        }
        if(i<n-m)
        {
            t=(d*(t-txt[i]*h)+txt[i+m])%q;
            if(t<0)
                t+=q;
        }
    }
}
int main()
{
    search("GEEKS FOR GEEKS","GEEK",10001);
    return 0;
}
