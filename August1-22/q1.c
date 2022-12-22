//1.	Write a program to add two distances (in KM -MTR)
// represented in the form of structure by passing structure to function.
#include <stdio.h>
struct distance
{
    float km,m;
    float total;
};
void add(struct distance a)
{
    a.total=0;
    a.total=a.km+a.m/1000;
    printf("\nTotal Distance:%f km",a.total);
}
int main()
{
    struct distance a;
    printf("\nEnter distance in km:\n");
    scanf("%f",&a.km);
    printf("\nEnter distance in meter:\n");
    scanf("%f",&a.m);
    add(a);
}