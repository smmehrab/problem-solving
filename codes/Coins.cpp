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

int main(){
    char s[100];
    int a=0,b=0,c=0,r=1;
    int t=3;

    while(t--){
        scanf("%s",s);
        if(s[1]=='=')
            r=0;

        else if(s[0]=='A' && s[2]=='B'){
            if(s[1]=='<'){
                b++;
                a--;
            }

            else{
                a++;
                b--;
            }
        }

        else if(s[0]=='B' && s[2]=='C'){
            if(s[1]=='<'){
                c++;
                b--;
            }
            else{
                b++;
                c--;
            }
        }

        else if(s[0]=='C' && s[2]=='A'){
            if(s[1]=='<'){
                a++;
                c--;
            }
            else{
                c++;
                a--;
            }
        }

        else if(s[0]=='B' && s[2]=='A'){
            if(s[1]=='<'){
                a++;
                b--;
            }
            else{
                b++;
                a--;
            }
        }

        else if(s[0]=='C' && s[2]=='B'){
            if(s[1]=='<'){
                b++;
                c--;
            }
            else{
                c++;
                b--;
            }
        }

        else if(s[0]=='A' && s[2]=='C'){
            if(s[1]=='<'){
                c++;
                a--;
            }
            else{
                a++;
                c--;
            }
        }
    }

    if(r){

        if(a==b || b==c || c==a)

            r=0;

        if(a<b && a<c && r){
            printf("A");
            if(b<c)
                printf("BC\n");
            else
                printf("CB\n");
        }

        if(b<c && b<a && r){
            printf("B");
            if(a<c)
                printf("AC\n");
            else
                printf("CA\n");
        }

        if(c<b && c<a && r){
            printf("C");
            if(a<b)
                printf("AB\n");
            else
                printf("BA\n");
        }
    }
    if(r==0)
        printf("Impossible\n");

    return 0;
}

