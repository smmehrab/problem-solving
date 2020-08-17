#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main(){

    int n,v,i,r,t;
    scanf("%d %d",&n,&v);

    if(v>=n){
        printf("%d\n",n-1);
        //main();
        return 0;
    }

    if(v==n-1){
        printf("%d\n",v);
        //main();
        return 0;
    }

    for(i=2,r=v,t=v;t<n-1;i++,t++)
        r+=i;

    printf("%d\n",r);
    //main();
    return 0;

}


