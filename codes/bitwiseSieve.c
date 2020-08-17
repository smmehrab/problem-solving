#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

int status[(100000000/32)+2];
void sieve()
{
	 int i, j, sqrtN;
     sqrtN = (int)( sqrt(100000000) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
		 if( Check(status[i>>5],i&31)==0)
		 {
	 		 for( j = i*i; j <= 100000000; j += (i<<1) )
			 {
				 status[j>>5]=Set(status[j>>5],j & 31)   ;
	 		 }
		 }
	 }
	  puts("2");
	 for(i=3;i<=N;i+=2) {if( check(status[i/32],i%32)==0) printf("%d\n",i);}
}

