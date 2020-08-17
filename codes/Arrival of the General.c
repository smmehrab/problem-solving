#include<stdio.h>

int main()
{

    int n,t,i=0,max,min,s[110];
    scanf("%d",&n);

    while(i<n)
    {
        scanf("%d",&s[i]);
        if(i==0)
        {
            max=i;
            min=i;
        }
        else{

            if(s[max]<s[i])
            {
                max=i;
            }
            if(s[min]>=s[i])
            {
                min=i;
            }
        }
        i++;
    }

    t=max+(n-1-min);

    if(max>min)
    {
        t--;
    }
    printf("%d\n",t);



    return 0;


}
