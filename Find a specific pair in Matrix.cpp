#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=5,mx=INT_MIN;
    int a[5][5] = {{ 1, 2, -1, -4, -20 },
                    { -8, -3, 4, 2, 1 }, 
                    { 3, 8, 6, 1, 3 },
                    { -4, -1, 1, 7, -6 },
                    { 0, -4, 10, -5, 1 }};
    int maxv=a[n-1][n-1],maxarr[5][5];
    maxarr[4][4]=maxv;
    for(int j=n-2;j>=0;j--)
    {
        if(a[n-1][j]>maxv)
            maxv=a[n-1][j];
        
        maxarr[n-1][j]=maxv;
    }
    maxv=a[n-1][n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(a[i][n-1]>maxv)
            maxv=a[i][n-1];
        maxarr[i][n-1]=maxv;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            if(maxarr[i+1][j+1]-a[i][j]>mx)
                mx=maxarr[i+1][j+1]-a[i][j];
            maxarr[i][j]=max(a[i][j],max(maxarr[i+1][j],maxarr[i][j+1]));
        }
    }
    cout<<mx;
    return 0;
}
