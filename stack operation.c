#include<stdio.h>
#include<stdlib.h>
int a[5];
int top=-1;
void push()
{
    int item;
    if(top==4)
    {
        printf("Stack overflow \n");
    }
    else
    {
        printf("Enter the values: ");
        scanf("%d",&item);
        top++;
        a[top]=item;
        printf("%d pushed into the stack \n",item);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        printf("%d popped from the stack \n",a[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("Stack is empty \n");
    }
    else
    {
        printf("Stack elements are:\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",a[i]);
        }
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("Enter the operation:\n");
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:printf("EXIT");
            exit(0);
            default:printf("Invalid");
        }
    }
    return 0 ;
}
