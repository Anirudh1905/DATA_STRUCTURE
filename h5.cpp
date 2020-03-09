#include <iostream>

using namespace std;

int main()
{   int n;
    char a[26]={};
    string s;
    cin>>n>>s;
    for(i=0;i<n;i++)
    {
        if((int)s[i]<97)
        {
           a[s[i]-65]++;
        }
        else
        a[s[i]-97]++;
    }
    if(a[0]>=1 && a[4]>=1 && a[8]>=1 && a[14]>=1 && a[20]>=1)
            cout<<"YES";
        else
            cout<<"No";
}
