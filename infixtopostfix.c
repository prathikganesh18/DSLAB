#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
void push(char c)
{
    if(top==max-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top]=c;
    }
}
char pop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int precedence(char c)
{

    if(c=='^')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char infix[max],postfix[max];
    char ch,temp;
    int i=0,j=0;
    printf("Enter infix expression: ");
    gets(infix);
    while((ch=infix[i++])!='\0')
    {
        if(isalnum(ch))
        {
            postfix[j++]=ch;
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while((temp=pop())!='(')
            {
                postfix[j++]=temp;
            }
        }
        else
        {
            while(precedence(stack[top])>=precedence(ch))
            {
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("postfix expression:%s\n",postfix);
    return 0;
}
