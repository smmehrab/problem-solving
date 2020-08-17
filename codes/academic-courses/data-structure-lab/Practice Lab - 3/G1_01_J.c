#include<stdio.h>
int digsum(int d)
{
    int k;
    if(d<10) return d;
    k=0;
    k+=(d/1000);
    d=d%1000;
    k+=(d/100);
    d=d%100;
    k+=(d/10)+(d%10);

    if(k>9) return digsum(k);
    else return k;

}
int main()
{
    char s[30],t[30];
    int x,y,i;
    double r;
    r=0.00;
    while(gets(s)!=0)
    {
            gets(t);
            x=0;
            i=0;
            while(s[i]!='\0' || i==0)
            {

                if(s[i]=='\n') break;
                if(s[i]>='a' && s[i]<='z')
                {
                    x+= (int) s[i]-(int) 'a';
                    x++;
                }
                else if(s[i]>='A' && s[i]<='Z')
                {
                    x+=(int) s[i]-(int) 'A';
                    x++;
                }
                i++;
            }
            i=0;
            y=0;
            while(t[i]!='\0' || i==0)
            {

                if(t[i]=='\n') break;
                if(t[i]>='a' && t[i]<='z')
                {
                    y+=(int) t[i]-(int) 'a';
                    y++;
                }
                else if(t[i]>='A' && t[i]<='Z')
                {
                    y+=(int) t[i]-(int) 'A';
                    y++;
                }
                i++;
            }

            x=digsum(x);
            y=digsum(y);

            if(x<y) r=((x*100.00)/y);
            else r=((y*100.00)/x);

            printf("%0.2lf %%\n",r);
            r=0.00;
    }
    return 0;
}
