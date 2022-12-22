/*Write a program to store the ’n’ employee information as follows
v. Name (Name should have fname, mname and lname and use structure within
structure)
vi. DoB (Date should have DD, MM, YYYY and use structure within structure)
vii. Account number
viii. Balance
Apply the following operation on it. 3. Print the names of all the customers having balance less than $200. 4.
 Add $100 in the balance of all the customers having more than $1000 in their
balance and then print the detail of those customers only with the
incremented value of their balance. */
#include <stdio.h>
struct employee
{
    struct fn
    {
        char fname[20],mname[20],lname[20];    
    }name;
    struct dob
    {
        int date,month,year;
    }DOB;
    int account;
    int balance;   
};
int main()
{
    int n;
    printf("Enter the number of employee:\n");
    scanf("%d",&n);
    struct employee e[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the name of employee(first name ,second name , last name):\n");
        scanf("%s",e[i].name.fname);
        scanf("%s",e[i].name.mname);
        scanf("%s",e[i].name.lname);
        printf("\nEnter date,month,and yerain format dd/mm/yyyy:\n");
        scanf("%d",&e[i].DOB.date);
        scanf("%d",&e[i].DOB.month);
        scanf("%d",&e[i].DOB.year);
        printf("\nEnter the account number:\n");
        scanf("%d",&e[i].account);
        printf("\nEnter the balance:\n");
        scanf("%d",&e[i].balance);
    }
    printf("\nEmployee having balance less than 200:\n");
    for(int i=0;i<n;i++)
    {
        if(e[i].balance<200)
        {
            printf("\nFull Name: ");
            printf("%s  ",e[i].name.fname);
            printf("%s  ",e[i].name.mname);
            printf("%s  ",e[i].name.lname);
            printf("\n");
            printf("Date of the birth:");
            printf("%d.",e[i].DOB.date);
            printf("%d.",e[i].DOB.month);
            printf("%d",e[i].DOB.year);
            printf("\n");
            printf("Account number:");
            printf("%d",e[i].account);
            printf("\n");
            printf("alance:");
            printf("%d",e[i].balance);
        }
        printf("\n");
    }
    printf("\nEmployee having balance more than 1000:\n");
    for(int i=0;i<n;i++)
    {
        if(e[i].balance >1000)
        {
            e[i].balance += 100;
            printf("\nFull Name: ");
            printf("%s  ",e[i].name.fname);
            printf("%s  ",e[i].name.mname);
            printf("%s  ",e[i].name.lname);
            printf("\n");
            printf("\nDate of the birth:");
            printf("%d.",e[i].DOB.date);
            printf("%d.",e[i].DOB.month);
            printf("%d",e[i].DOB.year);
            printf("\n");
            printf("\nAccount number:");
            printf("%d",e[i].account);
            printf("\n");
            printf("\nBalance:");
            printf("%d",e[i].balance);
        }
    }
}