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
#include<string.h>
int main()
{
    int t,n,m,o,cs=0,i,l,r,c;
    char s[100];

    scanf("%d",&t);

    int a[1000];

    while(t--){

        scanf("%d %d",&n,&m);

        printf("Case %d:\n",++cs);

        l=500;
        r=501;
        c=0;

        while(m--){

            scanf("%s", s);

            if(strcmp(s,"pushRight")==0) o=1;
            else if(strcmp(s,"pushLeft")==0) o=2;
            else if(strcmp(s,"popRight")==0) o=3;
            else if(strcmp(s,"popLeft")==0) o=4;


            if(o==3 || o==4) scanf("%d",&i);


            if(o==1){
                if(c>=n) printf("The queue is full\n");
                else{
                    a[r++]=i;
                    printf("Pushed in right: %d\n",i);
                    c++;
                }
            }

            else if(o==2){
                if(c>=n) printf("The queue is full\n");
                else{
                    a[l--]=i;
                    printf("Pushed in left: %d\n",i);
                    c++;
                }
            }
            else if(o==3){
                if(c==0) printf("The queue is empty\n");
                else{
                    printf("Popped from right: %d\n",a[--r]);
                    c--;
                }
            }
            else if(o==4){
                if(c==0) printf("The queue is empty\n");
                else{
                    printf("Popped from left: %d\n",a[++l]);
                    c--;
                }
            }
        }
    }
    return 0;
}
