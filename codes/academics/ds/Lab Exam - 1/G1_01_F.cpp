#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000000],c;
    scanf("%s", s);
    int i,j,k,l,n,m,a[1000]={0};
    l=strlen(s);

    for(i=0;i<l;i+=k)
    {
        c=s[i];
        j=i;
        k=0;
        while(s[j]==c)
        {
            k++;
            j++;
        }
        printf("%c%d",s[i],k);
    }
    printf("\n");
    return 0;
}
