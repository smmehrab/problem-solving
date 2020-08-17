#include<stdio.h>

int main()
{

    int n;
    scanf("%d",&n);

    int i,c=0;
    int a,b;

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if((b-a)>1)
        {
            c++;
        }
    }
    printf("%d\n",c);

    return 0;
}
