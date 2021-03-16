#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int>&st,int t)
{
    if(st.empty())
    {
        st.push(t);
        return;
    }
    int x=st.top();
    st.pop();
    insert(st,t);
    st.push(x);
}

void rev(stack<int>&st)
{
    if(st.size()==1)
        return;
    int x=st.top();
    st.pop();
    rev(st);
    insert_at_bottom(st,x);
}

int main()
{
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    rev(st);
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
