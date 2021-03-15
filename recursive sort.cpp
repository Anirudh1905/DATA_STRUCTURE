#include <bits/stdc++.h>
using namespace std;

void insert(vector<int>&v,int t)
{
    if(v.size()==0 || v[v.size()-1]<=t)
    {
        v.push_back(t);
        return;
    }
    int x=v[v.size()-1];
    v.pop_back();
    insert(v,t);
    v.push_back(x);
}
void sort(vector<int>&v)
{
    if(v.size()==1)
        return;
    int t=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v,t);
}

int main()
{
    vector<int>v{1,2,34,4,3,8,2,4,1};
    sort(v);
    for(auto x:v)
        cout<<x<<" ";
    return 0;
}
