#include<stdio.h>

int main()
{
    while(1){

    int n,a[120],i=0,j,x=0,y=0,t=0,one=0,c=0;

    scanf("%d",&n);

    while(i<n)
    {
        scanf("%d",&a[i]);
        if(a[i]==1){one++;}
        i++;
    }

    if(n==1)
    {
        if(a[0]==0){printf("1\n");}

        else{printf("0\n");}

        return 0;
    }

    if(one==0)
    {
        printf("%d\n",n);return 0;
    }

    else if(one==n)
    {
        n--;printf("%d\n",n);return 0;
    }

    i=0;

    while(i<n)
    {
        x=0;y=0;
        if(a[i]==1)
        {
            if( a[i+1]==0 && i+1<n)
            {
                j=i+1;
                while(a[j]!=1 && j<n){j++;}
                y=j-1-i;
            }

            else if( a[i+1]==1 && i+1<n)
            {
                j=i+1;
                while(a[j]!=0 && j<n){j++;y--;}
                if( a[j]==0 && j+1<n)
                {
                    j=j+1;
                    while(a[j]!=1 && j<n){j++;}
                    y=y+j-1-i;
                }

            }

            if(a[i-1]==0 && i!=0)
            {
                j=i-1;
                while(a[j]!=1 && j>=0){j--;}
                x=i-j-1;
            }

            else if(a[i-1]==1 && i!=0)
            {
                j=i-1;
                while(a[j]!=0 && j>=0){j--;x--;}
                if(a[j]==0 && j!=0)
                {
                    j=j-1;
                    while(a[j]!=1 && j>=0){j--;}
                    x=x+i-j-1;
                }

            }

            if(i==0){t=(x+y);}

            else if(t<(x+y)){t=(x+y); if(x>0 && y>0) {c=1;} else {c=0;}}

        }

        i++;
    }

    if(c==1){one--;}

    t=t+one;

    printf("%d\n",t);

    }return 0;
}
