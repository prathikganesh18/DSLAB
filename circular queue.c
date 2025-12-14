#include<stdio.h>
#define size 5
int Q[size];
int front=-1,rear=-1;
void insertcq()
{
    int item;
    printf("Enter the element: ");
    scanf("%d",&item);
    if(front==(rear+1)%size||front==0&&rear==size-1)
    {
        printf("Queue Overflow\n");
    }
    if(front==-1)
    {
        front=0;
        rear=0;
        Q[rear]=item;
    }
    else
    {
        rear=(rear+1)%size;
        Q[rear]=item;
    }
    printf("%d is inserted\n",item);
}
void deletecq()
{
    int item;
    if(front==-1)
    {
        printf("Queue Empty\n");
    }
    if(front==rear)
    {
        item=Q[front];
        front=-1;
        rear=-1;
    }
    else
    {
        item=Q[front];
        front=(front+1)%size;
    }
    printf("Deleted element is %d\n",item);
}
void displaycq()
{
    if(front==-1)
    {
        printf("Queue Empty\n");
    }
    printf("Queue elements:\n");
    int i=front;
    while(1)
    {
        printf("%d\n",Q[i]);
        if(i==rear)
        {
            break;
        }
        i=(i+1)%size;
    }
}
int main()
{
    int ch;
    while(1)
    {
        printf("-----Circular Queue Menu-----\n");
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertcq();break;
            case 2:deletecq();break;
            case 3:displaycq();break;
            case 4:return 0;
            default:printf("Invalid choice\n");

        }
    }
}
