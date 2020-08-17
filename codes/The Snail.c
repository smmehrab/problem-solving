#include <stdio.h>

int main() {
   float u,f,hc;
   int h,d,F,day;

   while(1){
       scanf("%d %f %d %d",&h,&u,&d,&F);
       if(h==0) break;

           f=(F*u)/100.00;
           hc=0;
           day=1;

           while(1){

                hc+=u;
               if(u>0) u-=f;
               if(hc>h) break;
               hc-=d;
               if(hc<0.00) break;
               day++;
           }

           if(hc<0) printf("failure on day %d\n", day);
           else printf("success on day %d\n", day);
   }
   return 0;
}
