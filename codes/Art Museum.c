#include<stdio.h>
int main()
{
    int n,x[300]={0},i,a,b,max=0,r=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a,&b);
        for(i=a;i<b;i++) x[i]++;
    }
    for(i=0;i<24;i++)
    {
        //printf("%d\n",x[i]);
        if(x[i]>max) max=x[i];//{r=0;max=x[i];}
        //else if(x[i]==max && max!=0) r++;
    }
    //printf("%d\n",r);
    printf("%d\n",max);
    return 0;
}
