/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    int c=0;
    int x,y,z;

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if((x==1 && y==1)||(x==1 && z==1)||(z==1 && y==1))
        {
            c++;
        }
        printf("\n");
    }
    printf("%d\n",c);
    return 0;
}
