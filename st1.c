#include <stdio.h>
#include <stdlib.h>
int a[100],top=-1,z,i,ch;
char y,o,m;
void push(int z)
{
    a[++top]=z;
}
void pop()
{
    scanf("%c",&y);
    top--;
}
void display()
{
    scanf("%c",&y);
    for(i=0;i<=top;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                scanf("%d %c",&z,&y);
                push(z);
                break;
            }
            case 2:
            {
                {
                    scanf("%c",&y);
                    pop();
                    break;
                }
            }
            case 3:
            {
                {
                    scanf("%c",&y);
                    display();
                    break;
                }
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }

        }
    }
    while(y!='n');
    return 0;
}
