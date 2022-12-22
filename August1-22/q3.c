//3.	Write a program to store employee’s information as name, gender, department, basic pay, 
//gross pay using one array of structure where gross pay is not the user input. 
//Calculate the gross pay using the following formula & assign the value in the individual employee’s 
//gross pay entry.
   //Gross Pay = basic pay + HR + DA
//Where HR=25% of basic
 //  DA= 75% of basic
 #include <stdio.h>
 #include <string.h>
 struct employee
 {
   char name[50],gender,department[100];
   float basic_pay,gross_pay,HR,DA; 
 };
int main()
{
   int n;
   printf("Enter the number of employee:\n");
   scanf("%d",&n);
   struct employee emp[n];
   for(int i=0;i<n;i++)
   {
      printf("\nEnter the name of %dth employee:",i);
      scanf("%s",emp[i].name);
      printf("\nEnter the gender of employee(one has to enter 'M' for male and 'F' for female):");
      scanf("%s",&emp[i].gender);
      printf("\nEnter the department of the employee:");
      scanf("%s",emp[i].department);
      printf("\nEnter the basic salary:");
      scanf("%f",&emp[i].basic_pay);
      emp[i].HR=0.25*emp[i].basic_pay;
      emp[i].DA=0.75*emp[i].basic_pay;
      emp[i].gross_pay=emp[i].basic_pay+emp[i].DA+emp[i].HR;
   }
   for(int i=0;i<n;i++)
   {
      printf("\nFor %dth employee:\n",i);
      printf("\nName:%s",emp[i].name);
      printf("\nGender:%c",emp[i].gender);
      printf("\nDepartment:%s",emp[i].department);
      printf("\nBasic Salary:%f",emp[i].basic_pay);
      printf("\nDA:%f",emp[i].DA);
      printf("\nHR:%f",emp[i].HR);
      printf("\nGross Salary:%f",emp[i].gross_pay);
      printf("\n");
   }
}