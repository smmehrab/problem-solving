#include<stdio.h>

int main()
{
    char s[100000];
    int i,c=0;

    scanf("%[^\r]", s);

        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]=='"')
            {
                c++;
                if((c%2)==1) {printf("``");}
                else{printf("''");}

            }
            else
            {
                printf("%c",s[i]);
            }
        }

    return 0;

}
