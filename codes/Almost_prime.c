#include<stdio.h>

int prime(int a[])
{

    int i,j=0,k,z;
    a[j]=2;
    j++;
    for(i=3;i<3000;i=i+2)
    {

            int prime=1;


            for(k=3;k<=55;k=k+2)
            {
                if(i%k==0 && i!=k)
                {
                    prime=0; break;}
            }
            if(prime==1)
            {a[j]=i;
            j++;}

    }

    return (j-1);


}

int main()
{
    int n,x,c=0,r=0,p,i;
    scanf("%d",&n);
    int a[3000];

    x=prime(a);






    for(i=2;i<=n;i++)
    {
        c=0;

        for(p=0;p<=x;p++)
        {
            if(i%a[p]==0)
            {
                c++;

            }
        }

        if(c==2){
            r++;
        }

    }
    printf("%d\n",r);
    return 0;

}
