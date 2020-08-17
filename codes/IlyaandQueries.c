#include<stdio.h>

int main()
{
    char s[100100];
    int m,x,y,j,k,i;

    gets(s);
    scanf("%d", &m);

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        k=0;
        for(j=x;j<y;j++)
        {
            if(s[j-1]==s[j])
            {
                k++;
            }
        }
        printf("%d\n",k);
    }

    return 0;
}
