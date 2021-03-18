#include <iostream>
#define n 5 
using namespace std;
int a[5],f=-1,r=-1;
void insert(int x)
{
    if(f==r+1 || r==n-1)
        cout<<"Queue is Full";
    else if(f==-1 && r==-1)
    {
        f=0;r=0;
        a[r]=x;
    }
    else if(r==n-1)
    {
        r=0;
        a[r]=x;
    }
    else
        a[++r]=x;
}
int pop()
{
    int x=-1;
    if(f==-1 && r==-1)
        cout<<"Queue is empty";
    else if(f==r)
    {
        x=a[f];
        f=-1;r=-1;
    }
    else if(f==n-1)
    {
        x=a[f];
        f=0;
    }
    else
        x=a[f++];
    return x;
}
void display()
{
    if(f==-1)
        cout<<"Queue Empty"<<endl;
    if(r>=f)
        for(int i=f;i<=r;i++)
            cout<<a[i]<<" ";
    else
    {
        for(int i=f;i<n;i++)
            cout<<a[i]<<" ";
        for(int i=0;i<=r;i++)
            cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    display();
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    display();
    return 0;
}
