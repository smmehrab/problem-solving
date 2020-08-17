/*#include<stdio.h>
#include<string.h>
int main()
{
    int n,counter[27]={0},diff=0,i,j,k,l;
    char s[100000];
    scanf("%d",&n);
    scanf("%s", s);

    for(i=0;i<n;i++)
    {
        j=s[i]-'a';
        counter[j]++;
    }

    for(i=0;i<26;i++) if(counter[i]!=0) diff++;


}
*/

#include <stdio.h>
#include<string.h>
int n,k,c=0;

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if (l == r) c++;
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
    int a,i,j,l,r;
    char s[100000];
    scanf("%d",&a);
    scanf("%s", s);
    for(i=1;i<a;i++) permute(s, 0, i);
    printf("%d\n",c);
    return 0;
}

