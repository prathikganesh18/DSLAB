#include<stdio.h>

int a[5];
int maxSize=5;
int top=-1;
//push
void push(int val){
    if(top==maxSize-1){
        printf("Stack Overflow\n");
        return;
    }else{
        a[++top]=val;
    }
}

int pop(){
    if(top==-1){
        printf("Stack is Empty\n");
        return -1;
    }else{
        return a[top--];
    }
}
void display(){
    if(top==-1){
        printf("Stack is Empty\n");
    }else{
        for(int i=top;i>-1;i--){
            printf("%d\n",a[top--]);
        }
    }
}

void main(){
    printf("Enter the array elements: \n");
    for(int i=0;i<maxSize;i++){
        int item;
        scanf("%d",&item);
        push(item);
    }

    printf("reversed array is \n");
    display();
}
