#include<stdio.h>
int main()
{
    int n=5,front=-1,rear=-1,a;
    int arr[n],item,i;
    printf("enter total number of elements to insert:\n");
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        printf("enter an element:\n");
        scanf("%d",&item);
        if(rear==n-1)
        {
            printf("Queue is full\n");
        }
        else if(front==-1)
        {
            front=0;
            rear=0;
            arr[rear]=item;
        }
        else
        {
            rear=rear+1;
            arr[rear]=item;
        }
    }
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else if(front==rear)
    {
        item=arr[rear];
        front=-1;
        rear=-1;
        printf("%d is deleted\n",item);
    }
    else
    {
        item=arr[rear];
        rear=rear-1;
        printf("%d is deleted\n",item);
    }
    printf("Queue elements are:\n");
    for(int j=front;j<=rear;j++)
    {
        printf("%d\n",arr[j]);
    }
    return 0;
}
