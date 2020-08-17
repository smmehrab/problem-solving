#include<stdio.h>
int main()
{
    int n,i;
    char it[5]="it",ihate[10]="I hate",thatilove[20]="that I love",thatihate[20]="that I hate";
    scanf("%d",&n);
    printf("%s",ihate);
    for(i=2;i<=n;i++)
    {

        if(i%2==0)
        {
            printf(" ");

                printf("%s",thatilove);

        }
        else
        {printf(" ");
            printf("%s",thatihate);
        }

    }

printf(" ");
    printf("%s",it);
    printf("\n");
    return 0;
}
