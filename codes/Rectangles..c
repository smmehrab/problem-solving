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

int main()
{
    int n,m,minx,miny,i,j,cs=0,x1[10000],y1[10000],x2[10000],y2[10000],ans;

    scanf("%d",&n);

    while(n--){

        ans=1;
        scanf("%d",&m);

        for(i=0;i<m;i++)
            scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);


        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(j!=i) {
                    x2[i]-=x1[j];
                    if(x2[i]<0)
                        ans=0;
                    else if(i==0) {
                        minx=x2[i];
                    }
                    else if(x2[i]<minx) minx=x2[i];
                }
            }
        }



        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(j!=i) {
                    y2[i]-=y1[j];
                    if(y2[i]<0)
                        ans=0;
                    else if(i==0) {
                        miny=y2[i];
                    }
                    else if(y2[i]<miny) miny=y2[i];
                }
            }
        }

        if(ans) printf("Case %d: %d\n",++cs,(minx*miny));
        else printf("Case %d: %d\n",++cs,ans);

    }
    return 0;


}
