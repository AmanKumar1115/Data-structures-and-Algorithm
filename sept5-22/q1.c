/*WAP to take the input of your name character wise where each character is one node to linked list  
Implement :
1. Return the number of vowel;
2. Return the number of words;
3. Display the odd position character only;*/
#include <stdio.h>
#include <stdlib.h>
struct node 
{
    char c;
    struct node *next; 
};

struct node *InsertATEnd_char(struct node *start, char n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->c = n;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *q;
        for (q = start; q->next != NULL; q = q->next);
        q->next = temp;
    }
    return start;
}
int  count(struct node *start)
{  
    int z=0;
    while(start)
    {

        if(start->c == 'a' || start->c == 'e' || start->c == 'i' || start->c == 'o' || start->c == 'u' || start->c == 'A' || start->c == 'E' || start->c == 'I' || start->c == 'O' || start->c == 'U')
            z++;
        start=start->next;
    }
    return z;
}
int  word(struct node *start)
{  
    int z=0;
    while(start)
    {

        if(start->c==' ')
         z++;
        start=start->next;

    }
    return z;
}
void display_odd(struct node *start)
{
    printf("\nCharacter at odd position: ");
    int i=1;
    for(;start!=NULL;start=start->next,i++)
    {
        if(i%2==0)
            printf("%c",start->c);
    }

}
int main()
{
    int n;
    printf("\nEnter the number of letter in your name :\n");
    scanf("%d",&n);
    struct node * start=NULL;
    printf("\nEnter character of your name one by one :\n");
    for(int i=0;i<=n;i++)
    {
        char ch;
        scanf("%c",&ch);
        start=InsertATEnd_char(start,ch);
    }
    struct node * s=start;
    printf("\nName: ");
    for(s=start;s!=NULL;s=s->next)
        printf("%c",s->c);
    int v=count(start);
    printf("\nThe number if the vowel: %d",v);
    int k=word(start);
    printf("\nThe number if the word: %d",k+1);
    display_odd(start);

    
}