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
int abs(int n)
{
    if(n<0) n=(-1)*n;
    return n;
}

int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4,i,j,k,l,m,n;

    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

    if(x1!=x2 && y1==y2)
    {
        x3=x1;
        x4=x2;
        y3=y4=y1+abs(x2-x1);
    }

    else if(x1==x2 && y1!=y2)
    {
        y3=y1;
        y4=y2;
        x3=x4=x1+abs(y2-y1);

    }

    else if(x1!=x2 && y1!=y2 && x1==y1 && x2==y2)
    {
        y3=y1;
        x4=x1;
        x3=x2;
        y4=y2;
    }

    else if(x1!=x2 && y1!=y2 && abs(y1-y2)==abs(x1-x2))
    {
        x3=x1;
        if(y1<y2) y3=y1+abs(y2-y1);
        else y3=y1-abs(y2-y1);

        x4=x2;
        y4=y1;
    }



    else
    {
        printf("-1\n");
        return 0;
    }

    printf("%d %d %d %d\n",x3,y3,x4,y4);
    return 0;

}
