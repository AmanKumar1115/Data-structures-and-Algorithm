/*4.  Let one student structure is having following data members.
a.  Roll number (int) b.  Name (string) c.  Marks of 5 subjects (array of int) d.  Percentage of mark (float) e.  Grade (Char)
WAP to do the following work (use function)
i.  Take students information (User will give the input for members like roll number, name & marks of 5 subjects)
ii.  Find the percentage of mark and grade from the percentage for each student and store the value in appropriate student’s data member’s entry.
iii.  Sort the student database according to the percentage*/
#include <stdio.h>
#include <string.h>
struct student
{
    int Roll_number, Marks[5];
    char name[50], grade;
    float percentage;
};
int main()
{
    int n;
    printf("\nEnter the number of the student:");
    scanf("%d", &n);
    struct student std[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the name of %dth Student:", i);
        scanf("%s", std[i].name);
        printf("\nEnter the Roll number of %dth student:", i);
        scanf("%d", &std[i].Roll_number);
        printf("\nEnter marks of  five subject of %dth student one by one:\n", i);
        float tm = 0;
        for (int k = 0; k < 5; k++)
        {
            scanf("%d", &std[i].Marks[k]);
            tm = tm + std[i].Marks[k];
        }
        printf("\nTotal marks:%f \n",tm);
        std[i].percentage = tm * 100 / 500;
        if (std[i].percentage >= 90)
            std[i].grade = 'O';
        else if (std[i].percentage >= 80 && std[i].percentage < 90)
            std[i].grade = 'A';
        else if (std[i].percentage >= 70 && std[i].percentage < 80)
            std[i].grade = 'B';
        else if (std[i].percentage >= 60 && std[i].percentage < 50)
            std[i].grade = 'C';
        else if (std[i].percentage >= 33 && std[i].percentage < 40)
            std[i].grade = 'D';
        else
            std[i].grade = 'F';
    }
    printf("\nDetails of student after sorting:\n");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (std[j].percentage < std[j + 1].percentage)
            {
                struct student std1 = std[j];
                std[j] = std[j + 1];
                std[j + 1] = std1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("\n\n");
        printf("\nName:%s", std[i].name);
        printf("\nRoll Number:%d", std[i].Roll_number);
        printf("\nMarks: ");
        for (int j = 0; j < 5; j++)
            printf("%d  ", std[i].Marks[j]);
        printf("\nPercentage:%f", std[i].percentage);
        printf("\nGrade:%c", std[i].grade);
    }
}