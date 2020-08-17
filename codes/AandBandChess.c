#include<stdio.h>

int main()
{
    char t,c;
    int i,j,w,b;

    w=0;b=0;

    i=1;

    while(i<=8)
    {
        j=1;
        while(j<=8)
        {
            if(j==8){scanf("%c%c",&t,&c);}
            else {scanf("%c",&t);}
            if(t=='Q')
            {
                w+=9;
            }
            else if(t=='R')
            {
                w+=5;
            }
            else if(t=='B')
            {
                w+=3;
            }
            else if(t=='N')
            {
                w+=3;
            }
            else if(t=='P')
            {
                w+=1;
            }
            else if(t=='q')
            {
                b+=9;
            }
            else if(t=='r')
            {
                b+=5;
            }
            else if(t=='b')
            {
                b+=3;
            }
            else if(t=='n')
            {
                b+=3;
            }
            else if(t=='p')
            {
                b+=1;
            }
            else if(t=='.' || t=='k' || t=='K')
            {
                w+=0;b+=0;
            }
            j++;
        }

        i++;
    }




    if(w>b)
    {
        printf("White\n");
    }
    else if(w<b)
    {
        printf("Black\n");
    }
    else
    {
        printf("Draw\n");
    }

    return 0;

}
