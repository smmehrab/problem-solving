#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,j;
    char r,s;

    scanf("%d",&n);
    scanf("%c",&r);

    char str[n+5][110];

    for(i=0;i<n;i++) gets(str[i]);

    scanf("%d",&m);

    scanf("%c",&s);
    for(i=1;i<=m;i++)
    {
         int t=0;
         char result[110];
         scanf("%s",result);
         for(j=0;j<n;j++)
         {
             int c=strcmp(result,str[j]);
             if(c==0)
             {t=1;break;}
         }

         if(t==0) printf("NO\n");
         else printf("YES\n");
    }
    return 0;
}
