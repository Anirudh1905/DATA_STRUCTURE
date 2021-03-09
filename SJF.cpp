// c++ program to implement Shortest Job first
#include<bits/stdc++.h>
using namespace std;
 
struct Process
{
   int pid;     // process ID
   int bt;      // burst Time
};
 
bool comparison(Process a, Process b)
{
    return (a.bt < b.bt);
}
 
// function to find the waiting time for all processes
void findWaitingTime(Process proc[], int n, int wt[])
{
    wt[0]=0;
    for(int i=1;i<n;i++)
        wt[i]=proc[i-1].bt+wt[i-1];
}
 
// function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    for(int i=0;i<n;i++)
        tat[i]=proc[i].bt+wt[i];
}
 
// function to calculate average time
void findAverageTime(Process proc[], int n)
{
    int wt[n],tat[n],t_wt=0,t_tat=0;
    findWaitingTime(proc,n,wt);
    findTurnAroundTime(proc,n,wt,tat);
    for(int i=0;i<n;i++)
    {
        t_wt+=wt[i];
        t_tat+=tat[i];
    }
    cout<<"Average Waiting time: "<<t_wt/(n*1.0)<<endl;
    cout<<"Average Turnaround time: "<<t_tat/(n*1.0)<<endl;
}
 
// main function
int main()
{
    Process proc[] = {{1, 21}, {2, 3}, {3, 6}, {4, 2}};
    int n = sizeof proc / sizeof proc[0];
    sort(proc,proc+n,comparison);
    for(int i=0;i<n;i++)
        cout<<proc[i].pid<<" ";
    cout<<endl;
    findAverageTime(proc,n);
    return 0;
}
