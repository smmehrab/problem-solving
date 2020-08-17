#include<stdio.h>

int main()
{

    char a[1100][10];
    int n,i,c=0;

    scanf("%d",&n);

    i=0;
    while(i<n)
    {
        scanf("\n%c",&a[i][0]);scanf("%c",&a[i][1]);scanf("%c",&a[i][2]);scanf("%c",&a[i][3]);scanf("%c",&a[i][4]);

        if(a[i][0]=='O' && a[i][1]=='O' && c!=1){a[i][0]='+';a[i][1]='+';c=1;}

        else if(a[i][3]=='O' && a[i][4]=='O' && c!=1){a[i][3]='+';a[i][4]='+';c=1;}

        i++;
    }

    if(c!=1){printf("NO\n");}
    else if(c==1){printf("YES\n");for(i=0;i<n;i++){printf("%c%c%c%c%c\n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4]);}}
    return 0;
}
