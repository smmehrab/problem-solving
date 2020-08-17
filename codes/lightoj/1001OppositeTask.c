#include<stdio.h>
 
int main()
{
    int total,z,x,y;
    scanf("%d",&total);
 
    for(z=0;z<total;z++)
    {
        scanf("%d",&x);
        if(x>10)
        {
            x=x-10;
            y=10;
            printf("%d %d\n",x,y);
         }
 
        else
        {
             y=0;
             printf("%d %d\n",x,y);
 
         }
 
 
 
 
    }
 
    return 0;
 
 
}