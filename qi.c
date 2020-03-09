#include <stdio.h>
#include <stdlib.h>
int front=0,rear=0,x,y,a[100],i;
void insertfront()
{
   scanf("%d",&x);
   if(front>0)
   {
       a[--front]=x;
   }
   else
    printf("not possible");
}
void insertback()
{
    scanf("%d",&y);
    a[rear++]=y;
}
void delfront()
{
    front++;
}
void delback()
{
    rear--;
}
void display()
{
    for(i=front;i<rear;i++)
    {
        printf("%d ",a[i]);
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
            case 1:insertfront();break;
            case 2:insertback();break;
            case 3:delfront();break;
            case 4:delback();break;
            case 5:display();break;
            default:printf("INVALID CHOICE\n");break;
        }
    }
    return 0;
}
