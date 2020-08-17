#include<stdio.h>

int main()
{


    int c[5],i=0,s=0,max=0;

    while(i<5)
    {
        scanf("%d",&c[i]);
        s=s+c[i];
        if(c[i]>max)
        {
            max=c[i];
        }
        i++;
    }

    i=0;

    while(i<=max)
    {
        if(max==0){printf("-1\n");break;}
        else if((5*i)==s){printf("%d\n",i);break;}
        else if(i==max){printf("-1\n");break;}
        i++;
    }

    return 0;



}
