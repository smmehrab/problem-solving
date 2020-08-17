#include <stdio.h>

struct TIME
{
  int seconds;
  int minutes;
  int hours;
};

void differenceBetweenTimePeriod(struct TIME start, struct TIME stop, struct TIME *diff)
{
    if(stop.seconds > start.seconds)
    {
        --start.minutes;
        start.seconds += 60;
    }

    if(stop.minutes > start.minutes)
    {
        --start.hours;
        start.minutes += 60;
    }

    diff->seconds = start.seconds - stop.seconds;
    diff->minutes = start.minutes - stop.minutes;
    diff->hours = start.hours - stop.hours;
}


int main()
{
    struct TIME startTime, stopTime, diff;

    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    scanf("%d %d %d", &stopTime.hours, &stopTime.minutes, &stopTime.seconds);

    differenceBetweenTimePeriod(startTime, stopTime, &diff);

    printf("%d %d %d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}

