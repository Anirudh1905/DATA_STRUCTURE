 #include <iostream>
using namespace std;
int main()
{
    string s;
    int a[100]={},i,l=0;
    char t;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        a[s[i]-65]++;
    }
    for(i=0;i<s.size();i++)
    {
        if(a[s[i]-65]>l)
        {
            l=a[s[i]-65];
            t=s[i];
        }
        else
        {
            if(s[i]<97)
            {
                l=a[s[i]-65];
                t=s[i];
            }
        }
    }
    cout<<t<<" "<<l;
    return 0;
}
