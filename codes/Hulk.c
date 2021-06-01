/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
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
