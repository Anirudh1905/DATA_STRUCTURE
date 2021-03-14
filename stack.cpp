#include <iostream>
using namespace std;

int a[100000],top=-1;
void push(int x)
{
    a[++top]=x;
}
void pop()
{
    top--;
}
int peek()
{
    return a[top];
}
bool empty()
{
    return top==-1;
}
int main()
{
    push(10);
    push(20);
    push(30);
    while(!empty())
    {
        cout<<peek();
        pop();
    }
    return 0;
}
