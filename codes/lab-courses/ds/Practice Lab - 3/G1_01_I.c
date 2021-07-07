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
    char s[1000];

    gets(s);

    if(s[1]=='\0')
    {

        if(s[0]>='a')
        {
            s[0]=s[0]-32;
            printf("%c\n",s[0]);
            return 0;
        }else
        {
            s[0]=s[0]+32;
            printf("%c\n",s[0]);
            return 0;
        }
    }

    int i=0,c;
    if(s[i]>='a')
    {
        c=1;
        i++;
        while(s[i]!='\0')
        {
            if(s[i]>='a')

            {i++; c=0;break;}
            i++;
        }

        if(c==1)
        {
           i=0;
           s[0]=s[0]-32;
           i++;
           while(s[i]!='\0')
           {s[i]=s[i]+32;i++;
           }
        }
    }
   else
   {
       c=1;

       i++;
       while(s[i]!='\0')
       {
           if(s[i]>='a')
           {
               c=0;
               i++;
           }

           i++;
        }
        if(c==1)
        {
           i=0;
           while(s[i]!='\0')
           {
                if(s[i]>='a')
                {
                    s[i]=s[i]-32;
                }
                else{
                s[i]=s[i]+32;}
                i++;
           }
        }
   }
    printf("%s\n",s);
   return 0;


}
