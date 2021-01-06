#include <iostream>

using namespace std;

int main()
{
    string s1,s2,res;
    cin>>s1>>s2>>res;
    if(s1.size()+s2.size()!=res.size())
        cout<<"false"<<endl;
    int j=0,k=0,i;
    for(i=0;i<res.size();i++)
    {
        if(s1[j]==res[i] && j<s1.size())
            j++;
        else if(s2[k]==res[i] && k<s2.size())
            k++;
        else
            break;
    }
    if(j+k!=res.size())
        cout<<"false";
    else
        cout<<"true";
    return 0;
}
