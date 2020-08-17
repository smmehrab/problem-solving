#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char ara[100][100]; int i,j;
    for(i =0; i<5; i++){
            scanf("%s",ara[i]);
            memset(ara+5,'.',20*sizeof(char));
    }
    bool ache = true;
    for(i = 0; i<5; i++){
        for(j=0; j<5; j++){
                if(ara[i][j]=='k'){
                    int m,n,o,p;
                    m = i+1;
                    n = i-1;
                    o = j+1;
                    p = j-1;
                    if(m<5){
                            if(ara[m][j+2]=='k'){
                                ache = false;
                               // printf("No  m pore i %d j %d\n",i,j);
                            }
                            if(ara[m][j-2]=='k'){
                                ache = false;
                                //printf("No  m age i %d j %d\n",i,j);
                            }
                    }
                    if(n>=0){
                            if(ara[n][j+2]=='k'){
                                ache = false;
                               // printf("No  n pore i %d j %d\n",i,j);
                                }
                            if(ara[n][j-2]=='k'){
                                ache = false;
                               // printf("No  n age i %d j %d\n",i,j);
                            }
                    }


                    if(o<5){
                            if(ara[o][i+2]=='k'){
                                ache = false;
                               // printf("No  o pore i %d j %d\n",i,j);
                            }
                            if(ara[o][i-2]=='k'){
                                ache = false;
                               // printf("No  o age i %d j %d\n",i,j);
                            }
                    }
                    if(p<5){
                            if(ara[p][i+2]=='k'){
                                ache = false;
                               // printf("No  p pore i %d j %d\n",i,j);
                            }
                            if(ara[p][i-2]=='k'){
                                ache = false;
                                //printf("No  p age\n i %d j %d",i,j);
                            }
                    }
                }

        }
    }
    if(ache){
        printf("valid\n");
    }
    else
        printf("invalid\n");




}
