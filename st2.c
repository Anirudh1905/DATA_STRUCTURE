#include <stdio.h>
#include <stdlib.h>
int a[100],ch,n,l,top=-1,x,i;
void display()
{
  if(top>=0)
  {
  	printf("Current Queue:\n");
  	for(i=0;i<=top;i++)
  	{
    	printf("[%d], ",a[i]);
  	}
  }
}
void push()
{
  scanf("%d",&x);
  a[++top]=x;
  display();
  printf("Pushed Value: %d\n",x);
}
void pop()
{
  l=a[top];
  top--;
  display();
  printf("Popped Value: %d\n",l);
}
int main()
{
  do
  {	scanf("%d",&ch);
  	switch(ch)
    {
      	case 1: {push();break;}
      	case 2: {pop();break;}
      	case 0: {printf("Qutting.");break;}
        default :{printf("Invalid input\n");break;}
    }
  }while(ch!=0);
	return 0;
}

