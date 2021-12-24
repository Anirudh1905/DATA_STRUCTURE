# Contributed by: Piyush Goel
#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int d;
    node *next;
    node(int x)
    {
        d=x;
    }
};

int main()
{
    vector<int>a={4,5,1,6,5,2,1,5,9,10,8};
    unordered_map<int,node*>mp;
    for(int i=0;i<a.size();i++)
    {
        mp[i]=new node(i);
    }
    for(int i=0;i<a.size();i++)
    {
        mp[i]->next=mp[a[i]];
    }
    vector<bool>vis(a.size(),0);int ans=-1;
    for(int i=0;i<a.size();i++)
    {
        if(vis[i])  continue;
        node* h=mp[i];vis[i]=1;
        node *s=h,*f=h;int flag=0;
        while(s && f && f->next)
        {
            s=s->next;
            vis[s->d]=1;
            f=f->next->next;
            if(s==f)
            {
                flag=1;
                break;
            }
        }
        s=h;
        while(s && f && s!=f && flag)
        {
            s=s->next;
            f=f->next;
        }node* tmp=s;int sum=0;
        while(s && flag)
        {
            vis[s->d]=1;
            sum+=s->d;
            s=s->next;
            if(s==tmp)
                break;
        }
        ans=max(ans,sum);
        if(flag)
        cout<<s->d<<endl;
    }
    cout<<ans;
    return 0;
}
