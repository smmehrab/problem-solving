#include<stdio.h>

int main()
{
    int x,y,n,i;

    scanf("%d %d %d",&x,&y,&n);

    for(i=1;i<=n;i++)
    {
        if(i%x!=0 && i%y!=0)
        {
            printf("%d",i);

        }
        else
        {


            if(i%x==0)
            {
                printf("Fizz");
            }
            if(i%y==0)
            {
                printf("Buzz");
            }
        }
        printf("\n");
    }
    return 0;
}
