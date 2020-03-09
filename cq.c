#include <stdio.h>
#include <stdlib.h>
int front=-1,rear=-1,x,y,a[100],i,n=10;
void insert()
{
    scanf("%d",&y);
    if(front==rear+1 || rear==n-1)
    {
        printf("Queue is full");
    }
    else if(front==-1 && rear==-1)
    {
        front=0;rear=0;
        a[rear]=y;
    }
    else if(rear==n-1)
    {
        a[rear]=y;
    }
    else
    {
        rear++;
        a[rear]=y;
    }
}
void del()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is EMPTY");
    }
    else if(front==rear)
    {
        x=a[front];
        front=rear=-1;
    }
    else if(front==n-1)
    {
        x=a[front];
        front=0;
    }
    else
    {
        x=a[front++];
    }
}
void display()
{
    if(rear>=front)
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d ",a[i]);
        }
    }
    else
    {
        for(i=front;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        for(i=0;i<rear;i++)
        {
            printf("%d ",a[i]);
        }
    }
}
int main()
{
    int ch=1;
    while(ch!=0)
    {
        scanf("%d",&ch);
        switch(ch)
        {
            case 0:printf("QUITTING\n");break;
            case 1:insert();break;
            case 2:del();break;
            case 3:display();break;
            default:printf("INVALID CHOICE\n");break;
        }
    }
    return 0;
}
