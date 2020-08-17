





/*#include<stdio.h>


int power(int n,int m)
{
    int i=0,r=1;
    while(i<m)
    {
        r=(r*n);
        i++;
    }

    return r;
}

int sm(int x,int m)
{
        int i=m-1;
        int sm=0;
        while(i>=1)
        {
            sm=sm+(x/(power(10,i)));
            x=(x%(power(10,i)));
            if(x<10)
            {
                sm=sm+x;

                return sm;
            }
            else {i--;}
        }
}

int main()
{
    while(1){

    int m,s,i,x,y;

    scanf("%d %d",&m,&s);

    if(s==0 && m==1){x=0;y=0;}

    if(s==0 && m!=1){x=-1;y=-1;}

    else if((s/10)>=m && s>m){x=-1;y=-1;}

    else if(m==1){x=s;y=s;}

    else{

    int im1=power(10,m)-1,im2=power(10,(m-1));

    while(im1>=im2)
    {
        if(sm(im1,m)>s&&im1==power(10,m)-1){x=-1;}
        if(sm(im1,m)==s){x=im1;break;}
        im1--;
    }

    while(im2<=x)
    {
        if(sm(im1,m)>s&&im1==power(10,m)-1){y=-1;}
        if(sm(im2,m)==s){y=im2;break;}
        im2++;

    }

    if((y<power(10,m)&&y>=power(10,m-1))==0){y=-1;}

    if((x<power(10,m)&&x>=power(10,m-1))==0){x=-1;}

    }

    printf("%d ",y);
    printf("%d\n",x);}
    return 0;

}
