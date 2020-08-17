#include <stdio.h>
int k;
char a[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void swap(char *x, char *y){
    char *temp;
    *temp = *x;
    *x = *y;
    *y = *temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if(!k) return;
   else if (l == r)
   {
        for(i=0;i<=r;i++)
            printf("%c",a[i]);
        printf("\n");
        k--;
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}

int main()
{
    int t,cs=0,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        printf("Case %d:\n",++cs);
        permute(a, 0, n-1);
    }
    return 0;
}

