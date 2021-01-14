#include <iostream>
#define R 3
#define C 3
using namespace std;

void print(string a[R][C],int r,string op)
{
    if(r==R)
    {
        if(op[0]==' ')
        {
            for(int i=1;i<op.size();i++)
                cout<<op[i];
        }
        else
            cout<<op;
        cout<<endl;return;
    }
    for(int i=0;i<C;i++)
    {
        if(a[r][i]!="")
        {   
            print(a,r+1,op+" "+a[r][i]);
        }
    }
}
int main()
{
    string a[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
    string op="";
    print(a,0,op);
    return 0;
}
