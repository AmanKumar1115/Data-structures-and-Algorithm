// 2.	WAP to implement the following function on the
// time value where the time is one structure element
// containing hour, minutes and second as the data member.
// i.	Addition of 2 time value
// ii.	Subtraction of 2 time value
// Note: Check the validity of result after operation
#include <stdio.h>
struct time
{
  int seconds;
  int minutes;
  int hours;
};

void differenceBetweenTimePeriod(struct time start, struct time stop, struct time *diff)
{
  while (stop.seconds > start.seconds)
  {
    --start.minutes;
    start.seconds += 60;
  }
  diff->seconds = start.seconds - stop.seconds;
  while (stop.minutes > start.minutes)
  {
    --start.hours;
    start.minutes += 60;
  }
  diff->minutes = start.minutes - stop.minutes;
  diff->hours = start.hours - stop.hours;
}

int main()
{
  printf("\n________________________________For Addition of two time values_____________________________________\n");
  struct time t1, t2, t3;
  printf("Enter the Time 1 (Hour,minute and Second):\n");
  scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);
  printf("\nEnter the Time 2 (Hour,minute and Second):\n");
  scanf("%d%d%d", &t2.hours, &t2.minutes, &t2.seconds);
  t3.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes + (t1.seconds + t2.seconds) / 60) / 60;
  t3.minutes = (t1.minutes + t2.minutes + (t1.seconds + t2.seconds) / 60) % 60;
  t3.seconds = (t1.seconds + t2.seconds) % 60;
  printf("\n Time 1 =%d hour : %d min : %d sec", t1.hours, t1.minutes, t1.seconds);
  printf("\n Time 2 =%d hour : %d min : %d sec", t2.hours, t2.minutes, t2.seconds);
  printf("\n Time 3,addition of time values is %d hour : %d min : %d sec", t3.hours, t3.minutes, t3.seconds);
  printf("\n_________________________For substraction of two time values_______________________________________");
  struct time startTime, stopTime, diff;
  printf("\nEnter the start time. \n");
  printf("\nEnter hours, minutes and seconds: ");
  scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
  printf("\nEnter the stop time. \n");
  printf("\nEnter hours, minutes and seconds: ");
  scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);
  differenceBetweenTimePeriod(startTime, stopTime, &diff);
  printf("\nTime Difference: %d hour : %d min :%d sec  - ", startTime.hours, startTime.minutes, startTime.seconds);
  printf("%d hour : %d min : %d sec ", stopTime.hours, stopTime.minutes, stopTime.seconds);
  printf("= %d hour : %d min : %d sec \n", diff.hours, diff.minutes, diff.seconds);
  return 0;
}
