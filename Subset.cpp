#include <bits/stdc++.h>

using namespace std;
vector<vector<int>>res;
void subset(vector<int>ip,vector<int>op)
{
    if(ip.size()==0)
    {
        res.push_back(op);
        return;
    }
    vector<int>op1=op;
    vector<int>op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    subset(ip,op1);
    subset(ip,op2);
    return;
}
int main()
{
    vector<int> vect1{ 1, 2, 3 }; 
    vector<int> vect2;
    subset(vect1,vect2);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
