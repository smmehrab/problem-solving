/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include<bits/stdc++.h>
#include<algorithm>
#include<string>
#include<math.h>

using namespace std;

int ifprime(int n){
    int i=2,c=1;
    if(n%i==0)
        c=0;
    else{
        for(i=3; i<=n/2; i+=2){
            if(n%i==0){
                c=0;
                break;
            }
        }
    }
    return c;
}

void find_ans(int n){

        if(ifprime(n) && !(n/10)){
            printf("%d\n",n);
            return;
        }

        else if(ifprime(n)){
            printf("-1\n");
            return;
        }

        int i,j,k[1000],ki=0,l,c,m;

        i=2;
        c=0;
        m=n;

        while(m%i==0){
            m/=i;
            c++;
        }

        l=pow(i,c);
        if(c){

            if(l>10){
                while(l>10){
                    k[ki]=i;
                    ki++;
                    l/=i;
                }
            }

            else{
                k[ki]=l;
                ki++;
            }
        }

        for(i=3;i<=(n/2);i+=2){

            c=0;
            while(m%i==0){
                m/=i;
                c++;
            }

            l=pow(i,c);

            if(c){
                if(l>10 && c>1){
                    while(l>10){
                        k[ki]=i;
                        ki++;
                        l/=i;
                    }
                }

                else{
                        printf("-1\n");
                        return;

                }
            }
        }

        sort(k,k+ki);

        for(i=0;i<ki;i++)
            printf("%d",k[i]);

        printf("\n");
        return;
}

int main(){
    int t,n;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        find_ans(n);
    }
    return 0;
}



