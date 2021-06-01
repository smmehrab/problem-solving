/*
************************************************
username    :   smmehrab
fullname    :   s.m.mehrabul islam
email       :   mehrab.24csedu.001@gmail.com
institute   :   university of dhaka, bangladesh
session     :   2017-2018
************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int k;
char str[30];

int compare (const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }

void swap (char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

int findCeil (char str[], char first, int l, int h)
{
    int i,ceilIndex = l;
    for (i = l+1; i <= h; i++)
      if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
    return ceilIndex;
}

void sortedPermutations ( char str[] )
{
    int size = strlen(str),i,isFinished = 0;
    qsort( str, size, sizeof( str[0] ), compare );

    while ( ! isFinished && k ){
        printf ("%s\n", str);
        k--;

        int i;
        for ( i = size - 2; i >= 0; --i )
           if (str[i] < str[i+1])
              break;

        if ( i == -1 )
            isFinished = 1;
        else{
            int ceilIndex = findCeil( str, str[i], i + 1, size - 1 );
            swap( &str[i], &str[ceilIndex] );
            qsort( str + i + 1, size - i - 1, sizeof(str[0]), compare );
        }
    }
}

int main()
{
    int t,n,i,cs=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(i=0;i<30;i++)
            str[i]='\0';
        for(i=0;i<n;i++)
            str[i]='A'+i;
        printf("Case %d:\n",++cs);
        sortedPermutations( str );
    }
    return 0;
}
