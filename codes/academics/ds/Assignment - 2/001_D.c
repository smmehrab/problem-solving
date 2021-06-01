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
    int r,c,i,j,m[100][100],max,min;
    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);

                if(j==0)
                {
                    max=m[i][j];
                    min=m[i][j];
                }
                if(max<m[i][j]) max=m[i][j];
                if(min>m[i][j]) min=m[i][j];
        }
        printf("Row %d Minimum: %d\nRow %d Maximum: %d\n",i,min,i,max);
    }
    return 0;
}


