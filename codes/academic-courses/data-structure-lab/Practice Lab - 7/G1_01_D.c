
#include<stdio.h>

int find_substr(char *a,char *b)
{
    int i,j,k=-1; char t;
    for(i=0,j=0;*(a+i)!='\0' && *(b+j)!='\0';i++)
    {
        if(*(a+i)==*(b+i))
        {
            k=1;
            j++;
        }
        else if(k==1) {j=0;k=-1;}
    }
    return k;
}

int main()
{
    char a[100000],b[100000];
    int i,ans;
    char *p,*q;
    p=a;q=b;

    for(i=0;;i++)
    {
        scanf("%c",&*(p+i));
        if(*(p+i)=='\n') break;
    }
    for(i=0;;i++)
    {
        scanf("%c",&*(q+i));
        if(*(q+i)=='\n') break;
    }

    ans=find_substr(a,b);
    printf("%d\n",ans);

    return 0;
}


