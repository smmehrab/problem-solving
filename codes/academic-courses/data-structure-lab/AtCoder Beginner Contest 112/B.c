#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,T,c[100000],t[100000],j,i,tle=1;
    scanf("%d %d",&n,&T);
    for(i=0;i<n;i++)
	{
		 scanf("%d %d",&c[i],&j);
		 t[c[i]]=j;
	}
    sort(c, c+n);
    for(i=0;i<n;i++)
    {
        if(t[c[i]]<=T)
        {
            printf("%d\n",c[i]);
			tle=0;
            break;
        }
    }
	if(tle) printf("TLE\n");
    return 0;
}
