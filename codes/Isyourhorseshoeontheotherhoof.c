#include<stdio.h>
#include<string.h>

int main()
{
    char s1[20],s2[20],s3[20],s4[20];
    int r=0;
    scanf("%s %s %s %s", s1, s2, s3, s4);

    if(strcmp(s1,s2)==0)
    {
        r++;
    }
    else if(strcmp(s1,s3)==0)
    {
        r++;
    }
    else if(strcmp(s1,s4)==0)
    {
        r++;
    }
    if(strcmp(s2,s3)==0)
    {
        r++;
    }
    else if(strcmp(s2,s4)==0)
    {
        r++;
    }
    if(strcmp(s3,s4)==0)
    {
        r++;
    }



    printf("%d\n",r);
    return 0;
}
