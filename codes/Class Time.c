#include<stdio.h>
#include<string.h>
int main()
{
   int i,j,n,k;
   char first[25][25],last[25][25],temp[25];
   scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%s %s", first[i], last[i]);

   for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
          if(strcmp(last[i],last[j])==0)
          {
              if(strcmp(first[i],first[j])>0)
              {
            strcpy(temp,first[i]);
            strcpy(first[i],first[j]);
            strcpy(first[j],temp);
            strcpy(temp,last[i]);
            strcpy(last[i],last[j]);
            strcpy(last[j],temp);
              }
          }
          else if(strcmp(last[i],last[j])>0)
          {
            strcpy(temp,last[i]);
            strcpy(last[i],last[j]);
            strcpy(last[j],temp);
            strcpy(temp,first[i]);
            strcpy(first[i],first[j]);
            strcpy(first[j],temp);
          }
      }
    }



   for(i=0;i<n;i++) printf("%s %s\n",first[i],last[i]);
   return 0;
}
