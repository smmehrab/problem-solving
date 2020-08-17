#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int n=5;
int a[n];

bool notTerminator(){
    for (int i = 0; i < n; ++i)
        if (a[i])
            return true;
    return false;
}

void scanner(){
    for (int i=0;i<n;++i)
        scanf("%d", &a[i]);
}

bool ifPos(int r, int i){
    if (i==n)
        return (r==23);

    int j = a[i++];
    return (ifPos(r+j, i) || ifPos(r-j, i) || ifPos(r*j, i));
}

int main(){
    while (scanner(), notTerminator()){
        sort(a, a+n);
        bool r = false;

        do{
            r = ifPos(a[0], 1);
            if(r)
                break;
        }while(next_permutation(a, a+n));

        if (r)
            puts("Possible");

        else
            puts("Impossible");
    }
}
