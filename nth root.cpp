// C++ Program to find
// n-th real root of x
#include <bits/stdc++.h>
using namespace std;

void findNthRoot(double x, int n)
{
    double l=1,h=x,eps=1e-6;
    while((h-l)>eps)
    {
        double m=(l+h)/2.0;
        if(pow(m,n)<x)
            l=m;
        else
            h=m;
    }
    cout<<l;
}

// Driver code
int main()
{
	double x = 10;
	int n = 2;
	findNthRoot(x, n);
}

// This code is contributed
// by Subhadeep
