#include <bits/stdc++.h>
#define n 5
using namespace std;
int a[n],f=0,r=0;
deque<int>dq;
void insert(int x)
{
    dq.push_front(x);
}
void pop()
{
    dq.pop_front();
}
void traverse()
{
    if(dq.size()==0)
    {
        cout<<"Queue Empty"<<endl;
        return;
    }
    while(dq.size())
    {
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    pop();
    pop();
    traverse();
    return 0;
}
