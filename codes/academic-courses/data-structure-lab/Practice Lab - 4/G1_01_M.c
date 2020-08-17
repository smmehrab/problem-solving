#include<stdio.h>

int main()
{


    int n,r=0;
    scanf("%d\n",&n);
    int s[100000],one=0,two=0,three=0,four=0;
    int i=0;
    while(i<n)
    {
        scanf("%d",&s[i]);
        if(s[i]==1) {one++;}
        if(s[i]==2) {two++;}
        if(s[i]==3) {three++;}
        if(s[i]==4) {four++;}
        i++;

    }

    r=r+four;
    if(three!=0)
    {


        if(three>=one)
        {
            r=r+three;
            one=0;
        }
        else
        {
            r=r+three;
            one=one-three;
        }

    }


    if(two!=0)
    {


        if(two%2==0)
        {
            r=r+(two/2);
            two=0;
        }

        else
        {
            r=r+(two/2)+1;
            two=0;

            if(one!=0)
            {
                if(one<3) one=0;
                else one=one-2;

            }

        }

    }
    if(one!=0)
    {
                if((one%4)==0)
                {
                    r=r+(one/4);
                }
                else
                {
                    r=r+(one/4)+1;
                }
                one=0;
    }




    printf("%d\n",r);

    return 0;






}
