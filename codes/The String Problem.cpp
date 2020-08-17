#include<bits/stdc++.h>
#include<algorithm>
#include<string>

using namespace std;

int main(){
    int t,m,n,i,j,k;
    char a[100010],b[100010];

    scanf("%d",&t);

    while(t--){
        int c[1000]={0};

        scanf("%d %d",&n,&m);
        scanf("%s", a);
        scanf("%s", b);

        for(i=0;i<n;i++){
            j= (int) a[i];
            c[j]++;
        }

        k=0;

        for(i=0;i<m;i++){

            j = (int) b[i];

            if(c[j])
                c[j]--;

            else
                break;

            if(i+1==m){
                i=-1;
                k++;
            }
        }

        printf("%d\n",k);

    }
}

