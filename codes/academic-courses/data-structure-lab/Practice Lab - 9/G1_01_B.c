#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct{
    int id;
    double x,y;
}Point;

double callDistance(Point a, Point b)
{
    double distance;
    distance=sqrt(((a.x-b.x)*(a.x-b.x))-((a.y-b.y)*(a.y-b.y)));
    return distance;
}

int main()
{
    int n,i,j,k,l,far_away;
    double distance,max_distance=0,closest=100000;

    Point s[1000];

    printf("Enter Number of Points:\n");
    scanf("%d",&n);

    s[0].id=0;
    s[0].x=0;
    s[0].y=0;

    for(i=1;i<=n;i++)
    {
        printf("Enter ID:\n");
        scanf("%d", &s[i].id);
        printf("Enter x co-ordinate:\n");
        scanf("%lf", &s[i].x);
        printf("Enter y co-ordinate:\n");
        scanf("%lf", &s[i].y);

        distance=callDistance(s[i],s[0]);
        if(distance>=max_distance)
        {
                far_away=i;
                max_distance=distance;
        }
    }

    for(i=1;i<=n;i++)
    {
        printf("\n");
        printf("ID: %d\n", s[i].id);
        printf("X = %lf , ", s[i].x);
        printf("Y = %lf\n", s[i].y);
    }

    i=far_away;
    printf("\nFAR AWAY POINT:\n");
        printf("ID: %d\n", s[i].id);
        printf("X = %lf , ", s[i].x);
        printf("Y = %lf\n", s[i].y);

    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            distance=callDistance(s[i],s[j]);
            if(distance<closest) closest=distance;
        }
    }

    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            distance=callDistance(s[i],s[j]);
            if(distance==closest)
            {
                printf("\n\n");
                printf("POINT 1:\n");
                printf("ID: %d\n", s[i].id);
                printf("X = %lf , ", s[i].x);
                printf("Y = %lf\n", s[i].y);
                printf("POINT 2:\n");
                printf("ID: %d\n", s[j].id);
                printf("X = %lf , ", s[j].x);
                printf("Y = %lf\n", s[j].y);
            }
        }
    }

    return 0;
}

