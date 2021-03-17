#include <iostream>
#define n 5
using namespace std;
int a[n],f=0,r=0;
void insert(int x)
{
    if(r==n)
    {
        cout<<"Queue Full"<<endl;
        return;
    }
    a[r++]=x;
}
void pop()
{
    if(f==r)
    {
        cout<<"Queue Empty"<<endl;
        return;
    }
    for(int i=f;i<r;i++)
        a[i]=a[i+1];
    r--;
}
void traverse()
{
    if(f==r)
    {
        cout<<"Queue Empty"<<endl;
        return;
    }
    for(int i=f;i<r;i++)
        cout<<a[i]<<" ";
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    traverse();
    pop();
    pop();
    traverse();
    return 0;
}
