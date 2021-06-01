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

#define N 10000001

using namespace std;

bitset<N> str;

void sieve(){
    long long unsigned i,j;
    for(i=0;i<N;i=i+2){
            if(i==2)
                continue;
            str[i]=1;
    }
    str[1]=0;

    for(i=3;i<N;i=i+2){
        if(str[i]==0){
            for(j=i+i;j<N;j=j+i){
                if(j%i==0)
                    str[j]=1;
            }
        }
    }

}
int main(){
    long long unsigned i, l, r, t, cnt, c, f;
    sieve();
    int caseno=0, cases;
    scanf("%d", &cases);
    while(cases--){
        scanf("%llu %llu", &l, &r);
        cnt = 0;
        for(i=l; i<=r; i++){
            if(i==1||i==2){
                cnt++;
                continue;
            }
            c = ceil(log(i)/log(2));
            f = floor(log(i)/log(2));
            if(c==f){
                cnt++;
                continue;
            }
            if(i%2!=0){
                c = ceil(sqrt(i));
                f = floor(sqrt(i));
                if(c==f){
                    if(!str[c])cnt++;
                }
            }
            else{
                t = i;
                while(t%2==0){
                    t = t/2;
                }
                c = ceil(sqrt(t));
                f = floor(sqrt(t));
                if(c==f){
                    if(!str[c])cnt++;
                }
            }
        }
        printf("Case %d: %llu\n", ++caseno, cnt);
    }

    return 0;
}
