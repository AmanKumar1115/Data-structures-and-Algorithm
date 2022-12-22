/* Wap to do the insertion in the bst and do the following on the created bst
i)Inorder traversal
ii)Pre order
iii)Post order
iv)Finding highest element in the tree
v)Find lowest element in the tree
vi)Display the content of tree in increasing order
vii)Find height. */
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
};
struct node *root = NULL;
struct node *createBinarytree(struct node *root, int x)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = x;
        root->rchild = root->lchild = NULL;
    }
    else if (x < root->data)
    {
        root->lchild = createBinarytree(root->lchild, x);
    }
    else if (x > root->data)
    {
        root->rchild = createBinarytree(root->rchild, x);
    }
    else
    {
        printf("\nDuplicate Element");
    }
    return root;
}
void preorder(struct node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void Inorder(struct node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}
int height(struct node *root)
{
    int x, y;
    if (root)
    {
        x = height(root->lchild);
        y = height(root->rchild);
        return x > y ? x + 1 : y + 1;
    }
    return 0;
}
int highest(struct node *root)
{
    if (root == NULL)
        return -999;
    while (root->rchild)
        root = root->rchild;
    return root->data;
}
int lowest(struct node *root)
{
    if (root == NULL)
        return -999;
    while (root->lchild)
        root = root->lchild;
    return root->data;
}
void increasing_order(struct node *root)
{
    if (root)
    {
        increasing_order(root->lchild);
        printf("%d ", root->data);
        increasing_order(root->rchild);
    }
}
int main()
{
    int n, r;
    printf("\nEnter the number of element:");
    scanf("%d", &n);
    printf("\nEnter the elememt one by one:\n");
    for (int i = 0; i < n; i++)
    {
        int e;
        scanf("%d", &e);
        root = createBinarytree(root, e);
    }
    do
    {
        printf("\nSelect from the given menu:");
        printf("\n1. Preorder Traversal");
        printf("\n2. Inorder Traversal");
        printf("\n3. Postorder Traversal");
        printf("\n4. Highest element");
        printf("\n5. Lowest element");
        printf("\n6. Height");
        printf("\n7. Increasing order");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nPreorder Traversal:");
            preorder(root);
            break;
        case 2:
            printf("\nInorder Traversal:");
            Inorder(root);
            break;
        case 3:
            printf("\nPostorder Traversal:");
            postorder(root);
            break;
        case 4:
            printf("\nHighest element: %d", highest(root));
            break;
            printf("\nHeight: %d", height(root));
            break;
        case 5:
            printf("\nLowest element: %d", lowest(root));
            break;
        case 6:
            printf("\nHeight: %d", height(root));
            break;
        case 7:
            printf("\nIncreasing order:");
            increasing_order(root);
            break;
        default:
            printf("\nINVALID CHOICE: ");
            break;
        }
        printf("\nEnter 1 to go to menu and o to exit: ");
        scanf("%d", &r);
    } while (r);
    return 0;
}