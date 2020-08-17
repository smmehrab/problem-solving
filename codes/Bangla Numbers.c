#include<stdio.h>
void print(unsigned long long int n, char k)
{
    if(n!=0)
    {
        printf("%llu ",n);
        if(k == 'k') printf("kuti ");
        if(k == 'l') printf("lakh ");
        if(k == 'h') printf("hajar ");
        if(k == 's') printf("shata ");
    }

}

int main()
{
    unsigned long long int n,c=0,k,l,h,s,d,l1,h1,s1,d1,l2,h2,s2,d2;
    k=0;l=0;h=0;s=0;d=0;
    l1=0;h1=0;s1=0;d1=0;
    l2=0;h2=0;s2=0;d2=0;

    while(scanf("%llu",&n)==1)
    {
        k=0;l=0;h=0;s=0;
        c++;
        printf("%d. ",c);

        d=(n%100);
        n=n/100;
        s=(n%10);
        n=n/10;
        h=(n%100);
        n=(n/100);
        l=(n%100);
        n=(n/100);
        k=(n%100);
        n=(n/100);
            if(k>=100)
            {
                    d1=(n%100);
                    n=n/100;
                    s1=(n%10);
                    n=n/10;
                    h1=(n%100);
                    n=(n/100);
                    l1=(n%100);
                    n=(n/100);
                    k=(n%100);
                    n=(n/100);
                        if(k>=100)
                        {
                            d2=(n%100);
                            n=n/100;
                            s2=(n%10);
                            n=n/10;
                            h2=(n%100);
                            n=(n/100);
                            l2=(n%100);
                            n=(n/100);
                            k=(n%100);
                            n=(n/100);
                        }
            }

        print(k,'k');
        print(l2,'l');
        print(h2,'h');
        print(s2,'s');
        print(d2,'k');

        print(l1,'l');
        print(h1,'h');
        print(s1,'s');
        print(d1,'k');

        print(l,'l');
        print(h,'h');
        print(s,'s');
        print(d,'x');


    }
    return 0;
}
