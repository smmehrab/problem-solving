#include<stdio.h>

long long int n,t,x[2001000],z[2001000]={0},i,j,k=0;

int main()
{
    scanf("%lld",&n);

    for(i=1;i<=(2*n);i++)
    {
        scanf("%d",&x[i]); z[x[i]]++;
    }


    //for(i=1;i<=n;i++)
    //{
      //  for(j=n+1;j<=(2*n);j++)
        //{
          //  if(z[(x[i]^x[j])]!=0) k++;
        //}
    //}

    //if(k%2==0)
        printf("Karen\n");
    //else printf("Koyomi\n");

    return 0;
}
