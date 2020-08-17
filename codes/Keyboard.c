#include<stdio.h>

int main()
{
    char a[]="qwertyuiopasdfghjkl;zxcvbnm,./";
    char i[110],rl;int j=0,k=0;
    scanf("%c\n",&rl);
    gets(i);

    while(i[j]!='\0')
    {
        k=0;
        while(a[k]!=i[j])
        {k++;}
        if(rl=='R') {printf("%c", a[k-1]);}
        else if(rl=='L'){printf("%c",a[k+1]);}
        j++;
    }
    printf("\n");
    return 0;

}
