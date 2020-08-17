
#include<stdio.h>
#include<string.h>

void stringMerger(char *a, char *b, int position)
{
    int i,j,k=-1; char t;
    for(i=0;i<position-1;i++)
    {
        if(*(a+i)=='\0')
        {
            position =i;
            break;
        }
    }

    for(i=position,j=0;*(b+j)!='\0';i++,j++) *(a+i)=*(b+j);
}

int main()
{
    char a[100000],b[100000];
    int i,ans,position;
    char *p,*q;
    p=a;q=b;

    for(i=0;;i++)
    {
        scanf("%c",&*(p+i));
        if(*(p+i)==' ' ||*(p+i)=='\n') break;
    }
    for(i=0;;i++)
    {
        scanf("%c",&*(q+i));
        if(*(q+i)==' '||*(q+i)=='\n') break;
    }
    scanf("%d",&position);

    stringMerger(a,b,position);
    for(i=0;*(p+i)!='\0';i++) printf("%c",*(p+i));
    printf("\n");

    return 0;
}

