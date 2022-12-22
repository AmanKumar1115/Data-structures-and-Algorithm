// Write a program to check if a singly linked list is a palindrome
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int info;
    struct node *next;
};
struct node *insert(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *q;
        for (q = start; q->next != NULL; q = q->next)
            ;
        q->next = temp;
    }
    return start;
}
struct node *getMid(struct node *head)
{
    struct node *fast = head->next;
    struct node *slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
struct node *reverse(struct node *head)
{

    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct node *head)
{
    if (head->next == NULL)
        return true;
    struct node* middle = getMid(head);
    struct node* temp = middle->next;
    middle->next = reverse(temp);
    struct node *head1 = head;
    struct node *head2 = middle->next;
    while (head2 != NULL)
    {
        if (head2->info != head1->info)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
int main()
{
    struct node *start = NULL;
    printf("\nEnter the number of the element in the linked list: ");
    int n;
    scanf("%d", &n);
    printf("\nEnter data:");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        start = insert(start, e);
    }
    bool x = isPalindrome(start);
    if (x)
        printf("\nLinked list is a pallindrome!!");
    else
        printf("\nLinked list is not a pallindrome!!");
    return 0;
}
