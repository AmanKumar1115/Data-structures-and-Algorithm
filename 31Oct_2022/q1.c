//WAP to convert infix expression to postfix expression  and evalutee the expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct node
{
    char data;
    struct node *next;
} *top = NULL;
void push(char  x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct node *t;
    char x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}
char stackTop()
{
    if (!isEmpty())
        return top->data;
    return -1;
}
void display()
{
    struct node *p;
    p = top;
    while (p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

int out_stackpre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;
    else if (x == ')')
        return 0;
    return -1;
}
int in_stackpre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
    return -1;
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
        return 0;
    else
        return 1;
}
char *Intopost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (top == NULL || out_stackpre(infix[i]) > in_stackpre(top->data))
                push(infix[i++]);
            else if (out_stackpre(infix[i]) < in_stackpre(top->data))
                postfix[j++] = pop();
            else
            {
                char x = pop();
                i++;
            }
        }
    }
    while (top != NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}
int Eval(char *postfix)
{
    int i=0;
    int x1,x2,r;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            x2=pop();x1=pop();
            switch(postfix[i])
            {
                case '+': r = x1+x2;break;
                case '-': r = x1-x2;break;
                case '*': r = x1*x2;break;
                case '/': r = x1/x2;break;
                case '^': r = pow(x1,x2);break;
            }
            push(r);
        }
    }
    return top->data;
}
int main()
{
    char* infix = "(3^2*5)/(3*2-3)+5";
    char *postfix = Intopost(infix);
    printf("\nPostfix :%s",postfix);
    printf("\nResult is %d \n",Eval(postfix));
    return 0;
}